// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#include "pch.h"

#include "PushNotification-Test-Constants.h"
#include "BaseTestSuite.h"

using namespace WEX::Common;
using namespace WEX::Logging;
using namespace WEX::TestExecution;

using namespace winrt::Windows::ApplicationModel::Activation;
using namespace winrt::Windows::ApplicationModel::Background;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Foundation::Collections;
using namespace winrt::Windows::Management::Deployment;
using namespace winrt::Windows::Storage;
using namespace winrt::Windows::System;
using namespace winrt::Microsoft::Windows::PushNotifications;

void BaseTestSuite::ClassSetup()
{
    ::Test::Bootstrap::SetupPackages();
}

void BaseTestSuite::ClassCleanup()
{
    ::Test::Bootstrap::CleanupPackages();
}

void BaseTestSuite::MethodSetup()
{
    ::Test::Bootstrap::SetupBootstrap();

    bool isSelfContained{};
    VERIFY_SUCCEEDED(TestData::TryGetValue(L"SelfContained", isSelfContained));

    if (!isSelfContained)
    {
        ::WindowsAppRuntime::VersionInfo::TestInitialize(::Test::Bootstrap::TP::WindowsAppRuntimeFramework::c_PackageFamilyName,
                                                         ::Test::Bootstrap::TP::WindowsAppRuntimeMain::c_PackageFamilyName);
        VERIFY_IS_FALSE(::WindowsAppRuntime::SelfContained::IsSelfContained());
    }
    else
    {
        ::WindowsAppRuntime::VersionInfo::TestInitialize(L"I_don't_exist_package!", L"I_don't_exist_package!");
        VERIFY_IS_TRUE(::WindowsAppRuntime::SelfContained::IsSelfContained());
    }
}

void BaseTestSuite::MethodCleanup()
{
    if (!m_unregisteredFully)
    {
        PushNotificationManager::Default().UnregisterAll();
        m_unregisteredFully = true;
    }

    ::WindowsAppRuntime::VersionInfo::TestShutdown();
    ::Test::Bootstrap::CleanupBootstrap();
}

HRESULT BaseTestSuite::ChannelRequestHelper(IAsyncOperationWithProgress<PushNotificationCreateChannelResult, PushNotificationCreateChannelStatus> const& channelOperation)
{
    if (channelOperation.wait_for(c_timeout) != winrt::Windows::Foundation::AsyncStatus::Completed)
    {
        channelOperation.Cancel();
        RETURN_WIN32(ERROR_TIMEOUT); // timed out or failed
    }

    auto result{ channelOperation.GetResults() };
    auto status{ result.Status() };
    RETURN_HR_IF(result.ExtendedError(), status != PushNotificationChannelStatus::CompletedSuccess);

    result.Channel().Close();
    return S_OK;
}

void BaseTestSuite::RegisterWithPushNotificationManager()
{
    PushNotificationManager::Default().Register();
    m_unregisteredFully = false;
}

void BaseTestSuite::UnregisterAllWithPushNotificationManager()
{
    PushNotificationManager::Default().UnregisterAll();
    m_unregisteredFully = true;
}

void BaseTestSuite::ChannelRequestUsingNullRemoteId()
{
    if (PushNotificationManager::Default().IsSupported())
    {
        VERIFY_THROWS_HR(PushNotificationManager::Default().CreateChannelAsync(winrt::guid()).get(), E_INVALIDARG);
    }
    else
    {
        auto channelOperation{ PushNotificationManager::Default().CreateChannelAsync(winrt::guid()) };
        VERIFY_ARE_EQUAL(ChannelRequestHelper(channelOperation), E_FAIL);
    }
}

void BaseTestSuite::ChannelRequestUsingRemoteId()
{
    if (PushNotificationManager::Default().IsSupported())
    {
        auto channelOperation{ PushNotificationManager::Default().CreateChannelAsync(c_azureRemoteId) };
        VERIFY_SUCCEEDED(ChannelRequestHelper(channelOperation));
    }
    else
    {
        auto channelOperation{ PushNotificationManager::Default().CreateChannelAsync(c_azureRemoteId) };
        VERIFY_ARE_EQUAL(ChannelRequestHelper(channelOperation), E_FAIL);
    }
}

// Currently failing - https://github.com/microsoft/WindowsAppSDK/issues/2392
void BaseTestSuite::MultipleChannelClose()
{
    auto channelOperation{ PushNotificationManager::Default().CreateChannelAsync(c_azureRemoteId) };
    if (channelOperation.wait_for(c_timeout) != winrt::Windows::Foundation::AsyncStatus::Completed)
    {
        channelOperation.Cancel();
        VERIFY_FAIL(L"Channel request hit timeout.");
    }

    auto result{ channelOperation.GetResults() };
    VERIFY_ARE_EQUAL(result.Status(), PushNotificationChannelStatus::CompletedSuccess);

    result.Channel().Close();
    VERIFY_THROWS_HR(result.Channel().Close(), WPN_E_CHANNEL_CLOSED);
}

void BaseTestSuite::VerifyContentBuilderReturnsRefToSelf()
{
    auto b1{ Button(L"Button1") };

    auto b2{ Button(L"Button2") };
    auto b2a{ b2.AddArgument(L"action", L"Button2") };

    b1.AddArgument(L"action", L"Button1");   // A change to b1 only affects b1.
    b2a.AddArgument(L"action", L"Button2a"); // but a change to b2a will also affect b2 (as they point to the same object) 

    VERIFY_ARE_EQUAL(L"<actions><action content = \"Button1\" arguments = \"action=Button1\"/></actions>", b1.GetXml());
    VERIFY_ARE_EQUAL(L"<actions><action content = \"Button2\" arguments = \"action=Button2a\"/></actions>", b2.GetXml());
    VERIFY_ARE_EQUAL(L"<actions><action content = \"Button2\" arguments = \"action=Button2a\"/></actions>", b2a.GetXml());

    b1.AddArgument(L"action2", L"Button1");  // A change to b1 only affects b1.
    b2.AddArgument(L"action2", L"Button2");  // but a change to b2 will also affect b2a (as they point to the same object) 

    VERIFY_ARE_EQUAL(L"<actions><action content = \"Button1\" arguments = \"action2=Button1\"/></actions>", b1.GetXml());
    VERIFY_ARE_EQUAL(L"<actions><action content = \"Button2\" arguments = \"action2=Button2\"/></actions>", b2.GetXml());
    VERIFY_ARE_EQUAL(L"<actions><action content = \"Button2\" arguments = \"action2=Button2\"/></actions>", b2a.GetXml());
}

void BaseTestSuite::VerifyContentBuilderReturnsProperXml()
{
    winrt::hstring expected{
        L"<toast launch = \"action=ToastClick\">"\
            L"<visual>"\
                L"<binding template = \"ToastGeneric\">"\
                    L"<image "\
                        L"placement = \"appLogoOverride\" "\
                        L"hint - crop = \"circle\" "\
                        L"src = \"Path\\to\\Square150x150Logo.png\"/>"\
                    L"<text>Message1</text>"\
                    L"<text>Message2</text>"\
                L"</binding>"\
            L"</visual>"\
            L"<actions>"\
                L"<action "\
                    L"content = \"Open App\" "\
                    L"arguments = \"action=OpenApp\"/>"\
            L"</actions>"\
        L"</toast>"
    };

    auto xmlPayload{ AppNotificationContent()
        .AddArgument(L"action", L"ToastClick")
        .AddImage(Image(L"Path\\to\\Square150x150Logo.png")
            .SetUsesCircleCrop(true)
            .SetImagePlacement(ImagePlacement::AppLogoOverride))
        .AddText(Text(L"Message1"))
        .AddText(Text(L"Message2"))
        .AddButton(Button(L"Open App")
            .AddArgument(L"action", L"OpenApp"))
        .GetXml()
    };

    VERIFY_ARE_EQUAL(expected, xmlPayload);
}

void BaseTestSuite::ComparePerfBetweenFluentAndNonFluentBuilder()
{
    winrt::hstring expected{
        L"<toast launch = \"action=ToastClick\">"\
            L"<visual>"\
                L"<binding template = \"ToastGeneric\">"\
                    L"<image "\
                        L"placement = \"appLogoOverride\" "\
                        L"hint - crop = \"circle\" "\
                        L"src = \"Path\\to\\Square150x150Logo.png\"/>"\
                    L"<text>Message1</text>"\
                    L"<text>Message2</text>"\
                L"</binding>"\
            L"</visual>"\
            L"<actions>"\
                L"<action "\
                    L"content = \"Open App\" "\
                    L"arguments = \"action=OpenApp\"/>"\
            L"</actions>"\
        L"</toast>"
    };

    LARGE_INTEGER start;
    LARGE_INTEGER end;
    QueryPerformanceCounter(&start);

    auto xmlPayload1{ AppNotificationContent()
        .AddArgument(L"action", L"ToastClick")
        .AddImage(Image(L"Path\\to\\Square150x150Logo.png")
            .SetUsesCircleCrop(true)
            .SetImagePlacement(ImagePlacement::AppLogoOverride))
        .AddText(Text(L"Message1"))
        .AddText(Text(L"Message2"))
        .AddButton(Button(L"Open App")
            .AddArgument(L"action", L"OpenApp"))
        .GetXml()
    };
    QueryPerformanceCounter(&end);
    auto diff{ end.QuadPart - start.QuadPart };

    LARGE_INTEGER nfstart;
    LARGE_INTEGER nfend;
    QueryPerformanceCounter(&nfstart);

    auto nfi{ NFImage(L"Path\\to\\Square150x150Logo.png") };
    nfi.SetUsesCircleCrop(true);
    nfi.SetImagePlacement(ImagePlacement::AppLogoOverride);

    auto nfb{ NFButton(L"Open App") };
    nfb.AddArgument(L"action", L"OpenApp");

    auto nfc{ NFAppNotificationContent() };
    nfc.AddArgument(L"action", L"ToastClick");
    nfc.AddImage(nfi);
    nfc.AddText(NFText(L"Message1"));
    nfc.AddText(NFText(L"Message2"));
    nfc.AddButton(nfb);

    auto xmlPayload2{ nfc.GetXml() };

    QueryPerformanceCounter(&nfend);
    auto nfdiff{ nfend.QuadPart - nfstart.QuadPart };

    VERIFY_ARE_EQUAL(expected, xmlPayload1);
    VERIFY_ARE_EQUAL(expected, xmlPayload2);
}

void BaseTestSuite::VerifyRegisterAndUnregister()
{
    RegisterWithPushNotificationManager();

    PushNotificationManager::Default().Unregister();
}

void BaseTestSuite::VerifyUnregisterFails()
{
    if (PushNotificationManager::Default().IsSupported())
    {
        VERIFY_THROWS_HR(PushNotificationManager::Default().Unregister(), E_UNEXPECTED);
    }
    else
    {
        PushNotificationManager::Default().Unregister();
    }
}

void BaseTestSuite::VerifyUnregisterAllFails()
{
    if (PushNotificationManager::Default().IsSupported())
    {
        VERIFY_THROWS_HR(PushNotificationManager::Default().UnregisterAll(), E_UNEXPECTED);
    }
    else
    {
        PushNotificationManager::Default().UnregisterAll();
    }
}

void BaseTestSuite::VerifyRegisterAndUnregisterAll()
{
    RegisterWithPushNotificationManager();
    UnregisterAllWithPushNotificationManager();
}

void BaseTestSuite::MultipleRegister()
{
    RegisterWithPushNotificationManager();
    if (PushNotificationManager::Default().IsSupported())
    {
        VERIFY_THROWS_HR(PushNotificationManager::Default().Register(), HRESULT_FROM_WIN32(ERROR_ALREADY_REGISTERED));
    }
    else
    {
        PushNotificationManager::Default().Register();
    }
}

void BaseTestSuite::VerifyMultipleRegisterAndUnregister()
{
    RegisterWithPushNotificationManager();

    PushNotificationManager::Default().Unregister();

    if (PushNotificationManager::Default().IsSupported())
    {
        VERIFY_THROWS_HR(PushNotificationManager::Default().Register(), HRESULT_FROM_WIN32(ERROR_ALREADY_REGISTERED));
    }
    else
    {
        PushNotificationManager::Default().Register();
    }
}

void BaseTestSuite::VerifyMultipleRegisterAndUnregisterAll()
{
    RegisterWithPushNotificationManager();
    UnregisterAllWithPushNotificationManager();

    RegisterWithPushNotificationManager();
    UnregisterAllWithPushNotificationManager();
}

void BaseTestSuite::VerifyUnregisterTwice()
{
    RegisterWithPushNotificationManager();

    PushNotificationManager::Default().Unregister();
    if (PushNotificationManager::Default().IsSupported())
    {
        VERIFY_THROWS_HR(PushNotificationManager::Default().Unregister(), E_UNEXPECTED);
    }
    else
    {
        PushNotificationManager::Default().Unregister();
    }
}

void BaseTestSuite::VerifyUnregisterAllTwice()
{
    RegisterWithPushNotificationManager();
    UnregisterAllWithPushNotificationManager();

    if (PushNotificationManager::Default().IsSupported())
    {
        VERIFY_THROWS_HR(PushNotificationManager::Default().UnregisterAll(), E_UNEXPECTED);
    }
    else
    {
        PushNotificationManager::Default().UnregisterAll();
    }
}

void BaseTestSuite::VerifyUnregisterAndUnregisterAll()
{
    RegisterWithPushNotificationManager();
    PushNotificationManager::Default().Unregister();
    UnregisterAllWithPushNotificationManager();
}

void BaseTestSuite::VerifyForegroundHandlerSucceeds()
{
    PushNotificationManager::Default().PushReceived([](const auto&, PushNotificationReceivedEventArgs const& /* args */) {});
    RegisterWithPushNotificationManager();
}

void BaseTestSuite::VerifyForegroundHandlerFails()
{
    RegisterWithPushNotificationManager();
    if (PushNotificationManager::Default().IsSupported())
    {
        VERIFY_THROWS_HR(PushNotificationManager::Default().PushReceived([](const auto&, PushNotificationReceivedEventArgs const& /* args */) {}), HRESULT_FROM_WIN32(ERROR_NOT_FOUND));
    }
    else
    {
        PushNotificationManager::Default().PushReceived([](const auto&, PushNotificationReceivedEventArgs const& /* args */) {});
    }
}

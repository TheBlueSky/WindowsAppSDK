#pragma once
#include "Microsoft.Windows.PushNotifications.AppNotificationContent.g.h"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    struct AppNotificationContent : AppNotificationContentT<AppNotificationContent>
    {
        AppNotificationContent() = default;
        AppNotificationContent(ArgumentSerializer arguments);

        winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AddButton(Button button);
        winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AddImage(Image image);
        winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AddText(Text text);

        hstring GetXml();

    private:
        int m_lines{ 0 };
        Text m_text1{ L"default1" };
        Text m_text2{ L"default2" };
        Button m_button{ L"Default Button", ArgumentSerializer() };
        Image m_image{ winrt::Windows::Foundation::Uri(L"file://Path/to/Square150x150Logo.png") };
        ArgumentSerializer m_arguments{};
    };
}
namespace winrt::Microsoft::Windows::PushNotifications::factory_implementation
{
    struct AppNotificationContent : AppNotificationContentT<AppNotificationContent, implementation::AppNotificationContent>
    {
    };
}

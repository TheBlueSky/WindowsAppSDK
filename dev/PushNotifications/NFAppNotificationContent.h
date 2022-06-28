#pragma once
#include "Microsoft.Windows.PushNotifications.NFAppNotificationContent.g.h"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    struct NFAppNotificationContent : NFAppNotificationContentT<NFAppNotificationContent>
    {
        NFAppNotificationContent() = default;
        NFAppNotificationContent(NFArgumentSerializer arguments);

        void AddButton(NFButton button);
        void AddImage(NFImage image);
        void AddText(NFText text);

        hstring GetXml();

    private:
        int m_lines{ 0 };
        NFText m_text1{ L"default1" };
        NFText m_text2{ L"default2" };
        NFButton m_button{ L"Default Button", NFArgumentSerializer() };
        NFImage m_image{ winrt::Windows::Foundation::Uri(L"file://Path/to/Square150x150Logo.png") };
        NFArgumentSerializer m_arguments{};
    };
}
namespace winrt::Microsoft::Windows::PushNotifications::factory_implementation
{
    struct NFAppNotificationContent : NFAppNotificationContentT<NFAppNotificationContent, implementation::NFAppNotificationContent>
    {
    };
}

#pragma once
#include "Microsoft.Windows.PushNotifications.AppNotificationContent.g.h"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    struct AppNotificationContent : AppNotificationContentT<AppNotificationContent>
    {
        AppNotificationContent() = default;

        winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AddButton(Button button);
        winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AddText(Text text);

        hstring GetXml();

    private:
        std::wstring m_text1{};
        std::wstring m_text2{};
    };
}
namespace winrt::Microsoft::Windows::PushNotifications::factory_implementation
{
    struct AppNotificationContent : AppNotificationContentT<AppNotificationContent, implementation::AppNotificationContent>
    {
    };
}

#pragma once
#include "Microsoft.Windows.PushNotifications.AppNotificationButton.g.h"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    struct AppNotificationButton : AppNotificationButtonT<AppNotificationButton>
    {
        AppNotificationButton() = default;
        AppNotificationButton(hstring content);

        winrt::Microsoft::Windows::PushNotifications::AppNotificationButton AddArgument(hstring key, hstring value);

        // Retrieves the XML content of the button.
        hstring GetXml();

    private:
        std::wstring m_content{};

        // Argument
        std::wstring m_key{};
        std::wstring m_value{};
    };
}

namespace winrt::Microsoft::Windows::PushNotifications::factory_implementation
{
    struct AppNotificationButton : AppNotificationButtonT<AppNotificationButton, implementation::AppNotificationButton>
    {
    };
}

#pragma once
#include "Microsoft.Windows.PushNotifications.AppNotificationTextProperties.g.h"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    struct AppNotificationTextProperties : AppNotificationTextPropertiesT<AppNotificationTextProperties>
    {
        AppNotificationTextProperties() = default;

        winrt::Microsoft::Windows::PushNotifications::AppNotificationTextProperties SetLanguage(hstring language);

        winrt::Microsoft::Windows::PushNotifications::AppNotificationTextProperties UsesCallScenarioAlign();

        winrt::Microsoft::Windows::PushNotifications::AppNotificationTextProperties SetMaxLines(int maxLines);

    private:
        std::wstring m_text{};
    };
}

namespace winrt::Microsoft::Windows::PushNotifications::factory_implementation
{
    struct AppNotificationTextProperties : AppNotificationTextPropertiesT<AppNotificationTextProperties, implementation::AppNotificationTextProperties>
    {
    };
}

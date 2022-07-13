#pragma once
#include "Microsoft.Windows.PushNotifications.NFAppNotificationTextProperties.g.h"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    struct NFAppNotificationTextProperties : NFAppNotificationTextPropertiesT<NFAppNotificationTextProperties>
    {
        NFAppNotificationTextProperties() = default;

        void SetLanguage(hstring language);

        void UsesCallScenarioAlign();

        void SetMaxLines(int maxLines);

    private:
        std::wstring m_text{};
    };
}

namespace winrt::Microsoft::Windows::PushNotifications::factory_implementation
{
    struct NFAppNotificationTextProperties : NFAppNotificationTextPropertiesT<NFAppNotificationTextProperties, implementation::NFAppNotificationTextProperties>
    {
    };
}

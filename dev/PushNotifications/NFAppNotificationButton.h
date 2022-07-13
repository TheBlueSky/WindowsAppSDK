#pragma once
#include "Microsoft.Windows.PushNotifications.NFAppNotificationButton.g.h"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    struct NFAppNotificationButton : NFAppNotificationButtonT<NFAppNotificationButton>
    {
        NFAppNotificationButton() = default;
        NFAppNotificationButton(hstring content);

        void AddArgument(hstring key, hstring value);

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
    struct NFAppNotificationButton : NFAppNotificationButtonT<NFAppNotificationButton, implementation::NFAppNotificationButton>
    {
    };
}

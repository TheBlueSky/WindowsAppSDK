#pragma once
#include "Microsoft.Windows.PushNotifications.NFButton.g.h"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    struct NFButton : NFButtonT<NFButton>
    {
        NFButton(hstring content);

        void AddArgument(hstring key, hstring value);

        // Retrieves the XML content of the Text.
        hstring GetXml();

    private:
        std::wstring m_content{};
        std::wstring m_key{};
        std::wstring m_value{};
    };
}

namespace winrt::Microsoft::Windows::PushNotifications::factory_implementation
{
    struct NFButton : NFButtonT<NFButton, implementation::NFButton>
    {
    };
}

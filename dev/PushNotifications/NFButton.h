#pragma once
#include "Microsoft.Windows.PushNotifications.NFButton.g.h"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    struct NFButton : NFButtonT<NFButton>
    {
        NFButton(hstring content, NFArgumentSerializer arguments);

        // Retrieves the XML content of the Text.
        hstring GetXml();

    private:
        std::wstring m_content{};
        NFArgumentSerializer m_arguments{};
    };
}

namespace winrt::Microsoft::Windows::PushNotifications::factory_implementation
{
    struct NFButton : NFButtonT<NFButton, implementation::NFButton>
    {
    };
}

#pragma once
#include "Microsoft.Windows.PushNotifications.NFText.g.h"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    struct NFText : NFTextT<NFText>
    {
        NFText(hstring content);

        // Retrieves the XML content of the Text.
        hstring GetXml();

    private:
        std::wstring m_text{};
    };
}

namespace winrt::Microsoft::Windows::PushNotifications::factory_implementation
{
    struct NFText : NFTextT<NFText, implementation::NFText>
    {
    };
}


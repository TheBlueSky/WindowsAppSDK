#pragma once
#include "Microsoft.Windows.PushNotifications.Text.g.h"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    struct Text : TextT<Text>
    {
        Text(hstring content);

        // Retrieves the XML content of the Text.
        hstring GetXml();

    private:
        std::wstring m_text{};
    };
}

namespace winrt::Microsoft::Windows::PushNotifications::factory_implementation
{
    struct Text : TextT<Text, implementation::Text>
    {
    };
}


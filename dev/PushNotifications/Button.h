#pragma once
#include "Microsoft.Windows.PushNotifications.Button.g.h"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    struct Button : ButtonT<Button>
    {
        Button(hstring content);

        // Retrieves the XML content of the Text.
        hstring GetXml();

    private:
        std::wstring m_content{};
    };
}

namespace winrt::Microsoft::Windows::PushNotifications::factory_implementation
{
    struct Button : ButtonT<Button, implementation::Button>
    {
    };
}


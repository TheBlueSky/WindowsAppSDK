#pragma once
#include "Microsoft.Windows.PushNotifications.ArgumentSerializer.g.h"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    struct ArgumentSerializer : ArgumentSerializerT<ArgumentSerializer>
    {
        ArgumentSerializer() = default;

        winrt::Microsoft::Windows::PushNotifications::ArgumentSerializer AddArgument(hstring key, hstring value);

        hstring Serialize();

    private:
        std::wstring m_key{};
        std::wstring m_value{};
    };
}

namespace winrt::Microsoft::Windows::PushNotifications::factory_implementation
{
    struct ArgumentSerializer : ArgumentSerializerT<ArgumentSerializer, implementation::ArgumentSerializer>
    {
    };
}

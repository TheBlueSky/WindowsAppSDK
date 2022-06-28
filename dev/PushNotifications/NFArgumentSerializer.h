#pragma once
#include "Microsoft.Windows.PushNotifications.NFArgumentSerializer.g.h"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    struct NFArgumentSerializer : NFArgumentSerializerT<NFArgumentSerializer>
    {
        NFArgumentSerializer() = default;

        void AddArgument(hstring key, hstring value);

        hstring Serialize();

    private:
        std::wstring m_key{};
        std::wstring m_value{};
    };
}

namespace winrt::Microsoft::Windows::PushNotifications::factory_implementation
{
    struct NFArgumentSerializer : NFArgumentSerializerT<NFArgumentSerializer, implementation::NFArgumentSerializer>
    {
    };
}

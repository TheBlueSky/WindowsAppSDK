#include "pch.h"
#include "ArgumentSerializer.h"
#include "Microsoft.Windows.PushNotifications.ArgumentSerializer.g.cpp"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    winrt::Microsoft::Windows::PushNotifications::ArgumentSerializer ArgumentSerializer::AddArgument(hstring key, hstring value)
    {
        m_key = key;
        m_value = value;

        return *this;
    }

    hstring ArgumentSerializer::Serialize()
    {
        std::wstring xmlPayload{ L"" };

        xmlPayload.append( m_key + L"=" + m_value);

        return hstring(xmlPayload);
    }
}

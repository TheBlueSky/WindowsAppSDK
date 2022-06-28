#include "pch.h"
#include "NFArgumentSerializer.h"
#include "Microsoft.Windows.PushNotifications.NFArgumentSerializer.g.cpp"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    void NFArgumentSerializer::AddArgument(hstring key, hstring value)
    {
        m_key = key;
        m_value = value;
    }

    hstring NFArgumentSerializer::Serialize()
    {
        std::wstring xmlPayload{ L"" };

        xmlPayload.append( m_key + L"=" + m_value);

        return hstring(xmlPayload);
    }
}

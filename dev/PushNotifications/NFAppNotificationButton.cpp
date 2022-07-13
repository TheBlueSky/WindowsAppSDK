#include "pch.h"
#include "NFAppNotificationButton.h"
#include "Microsoft.Windows.PushNotifications.NFAppNotificationButton.g.cpp"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    NFAppNotificationButton::NFAppNotificationButton(hstring content)
    {
        m_content = content;
    }

    void NFAppNotificationButton::AddArgument(hstring key, hstring value)
    {
        m_key = key;
        m_value = value;
    }

    // Retrieves the XML content of the button.
    hstring NFAppNotificationButton::GetXml()
    {
        std::wstring xmlPayload{ L"" };

        xmlPayload.append(L"<actions>");
        xmlPayload.append(L"<action ");
        xmlPayload.append(L"content = \"" + m_content + L"\" ");
        xmlPayload.append(L"arguments = \"" + m_key + L"=" + m_value + L"\"/>");
        xmlPayload.append(L"</actions>");

        return hstring(xmlPayload);
    }
}

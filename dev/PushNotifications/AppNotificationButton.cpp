#include "pch.h"
#include "AppNotificationButton.h"
#include "Microsoft.Windows.PushNotifications.AppNotificationButton.g.cpp"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    AppNotificationButton::AppNotificationButton(hstring content)
    {
        m_content = content;
    }

    winrt::Microsoft::Windows::PushNotifications::AppNotificationButton AppNotificationButton::AddArgument(hstring key, hstring value)
    {
        m_key = key;
        m_value = value;

        return *this;
    }

    // Retrieves the XML content of the button.
    hstring AppNotificationButton::GetXml()
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

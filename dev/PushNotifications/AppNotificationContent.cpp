#include "pch.h"
#include "AppNotificationContent.h"
#include "Microsoft.Windows.PushNotifications.AppNotificationContent.g.cpp"

using namespace winrt::Windows::Data::Xml::Dom;

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AppNotificationContent::AddText(Text text)
    {
        if (m_lines == 0)
        {
            m_text1 = text;
            m_lines = 1;
        }
        else
        {
            m_text2 = text;
            m_lines = 2;
        }

        return *this;
    }

    winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AppNotificationContent::AddButton(Button button)
    {
        m_button = button;

        return *this;
    }

    hstring AppNotificationContent::GetXml()
    {
        std::wstring xmlPayload{ L"" };

        xmlPayload.append(L"<toast>");

        xmlPayload.append(L"<visual>");
        xmlPayload.append(L"<binding template = \"ToastGeneric\">");

        if (m_lines > 0)
        {
            xmlPayload.append(m_text1.GetXml());
        }

        if (m_lines > 1)
        {
            xmlPayload.append(m_text2.GetXml());
        }

        xmlPayload.append(L"</binding>");
        xmlPayload.append(L"</visual>");

        xmlPayload.append(m_button.GetXml());

        xmlPayload.append(L"</toast>");

        return hstring(xmlPayload);
    }
}

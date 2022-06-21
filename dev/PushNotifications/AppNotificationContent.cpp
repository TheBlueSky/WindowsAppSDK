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
        //m_text (text);

        return *this;
    }

    hstring AppNotificationContent::GetXml()
    {
        std::wstring xmlPayload{ L"<toast>" };

        if (m_lines > 0)
        {
            xmlPayload.append(m_text1.GetXml());
        }

        if (m_lines > 1)
        {
            xmlPayload.append(L";");
            xmlPayload.append(m_text2.GetXml());
        }

        xmlPayload.append(L"</toast>");

        return hstring(xmlPayload);
        //return L"<toast>Message1;Message2</toast>";
    }
}

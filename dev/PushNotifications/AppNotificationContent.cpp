#include "pch.h"
#include "AppNotificationContent.h"
#include "Microsoft.Windows.PushNotifications.AppNotificationContent.g.cpp"

using namespace winrt::Windows::Data::Xml::Dom;

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AppNotificationContent::AddText(Text text)
    {
        //m_text (text);

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

        if (!m_text1.empty())
        {
            xmlPayload.append(m_text1);
        }

        if (!m_text2.empty())
        {
            xmlPayload.append(L";");
            xmlPayload.append(m_text2);
        }

        xmlPayload.append(L"</toast>");

        //return hstring(xmlPayload);
        return L"<toast>Message1;Message2</toast>";
    }
}

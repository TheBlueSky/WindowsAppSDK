#include "pch.h"
#include "NFAppNotificationContent.h"
#include "Microsoft.Windows.PushNotifications.NFAppNotificationContent.g.cpp"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    void NFAppNotificationContent::AddArgument(hstring key, hstring value)
    {
        m_key = key;
        m_value = value;
    }

    void NFAppNotificationContent::AddButton(NFButton button)
    {
        m_button = button;
    }

    void NFAppNotificationContent::AddImage(NFImage image)
    {
        m_image = image;
    }

    void NFAppNotificationContent::AddText(NFText text)
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
    }

    hstring NFAppNotificationContent::GetXml()
    {
        std::wstring xmlPayload{ L"" };

        xmlPayload.append(L"<toast launch = \"" + m_key + L"=" + m_value +L"\">");

        xmlPayload.append(L"<visual>");
        xmlPayload.append(L"<binding template = \"ToastGeneric\">");

        xmlPayload.append(m_image.GetXml());

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

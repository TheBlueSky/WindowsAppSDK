#include "pch.h"
#include "NFButton.h"
#include "Microsoft.Windows.PushNotifications.NFButton.g.cpp"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{

    NFButton::NFButton(hstring content)
    {
        m_content = content;
    }

    void NFButton::AddArgument(hstring key, hstring value)
    {
        m_key = key;
        m_value = value;
    }


    hstring NFButton::GetXml()
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

#include "pch.h"
#include "Button.h"
#include "Microsoft.Windows.PushNotifications.Button.g.cpp"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{

    Button::Button(hstring content)
    {
        m_content = content;
    }

    winrt::Microsoft::Windows::PushNotifications::Button Button::AddArgument(hstring key, hstring value)
    {
        m_key = key;
        m_value = value;

        return *this;
    }


    hstring Button::GetXml()
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

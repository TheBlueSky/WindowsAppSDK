#include "pch.h"
#include "Button.h"
#include "Microsoft.Windows.PushNotifications.Button.g.cpp"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{

    Button::Button(hstring content, ArgumentSerializer arguments)
    {
        m_content = content;
        m_arguments = arguments;
    }

    hstring Button::GetXml()
    {
        std::wstring xmlPayload{ L"" };

        xmlPayload.append(L"<actions>");
        xmlPayload.append(L"<action ");
        xmlPayload.append(L"content = \"" + m_content + L"\" ");
        xmlPayload.append(L"arguments = \"" + m_arguments.Serialize() + L"\"/>");
        xmlPayload.append(L"</actions>");

        return hstring(xmlPayload);
    }
}

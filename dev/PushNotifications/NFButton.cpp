#include "pch.h"
#include "NFButton.h"
#include "Microsoft.Windows.PushNotifications.NFButton.g.cpp"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{

    NFButton::NFButton(hstring content, NFArgumentSerializer arguments)
    {
        m_content = content;
        m_arguments = arguments;
    }

    hstring NFButton::GetXml()
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

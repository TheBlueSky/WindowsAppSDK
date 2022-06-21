#include "pch.h"
#include "Button.h"
#include "Microsoft.Windows.PushNotifications.Button.g.cpp"

using namespace winrt::Windows::Data::Xml::Dom;

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{

    Button::Button(hstring content)
    {
        m_content = content;
    }

    hstring Button::GetXml()
    {
        std::wstring xmlPayload{ L"" };

        xmlPayload.append(L"<actions>");
        xmlPayload.append(L"<action content = \"" + m_content + L"\"/>");
        xmlPayload.append(L"</actions>");

        return hstring(xmlPayload);
    }
}

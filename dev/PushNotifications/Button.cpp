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
        std::wstring xmlPayload{ L"<toast>" };

        if (!m_content.empty())
        {
            xmlPayload.append(m_content);
        }

        xmlPayload.append(L"</toast>");

        return hstring(xmlPayload);
    }
}

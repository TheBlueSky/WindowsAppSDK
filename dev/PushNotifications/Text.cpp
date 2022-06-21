#include "pch.h"
#include "Text.h"
#include "Microsoft.Windows.PushNotifications.Text.g.cpp"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{

    Text::Text(hstring text)
    {
        m_text = text;
    }

    hstring Text::GetXml()
    {
        std::wstring xmlPayload{ L"" };

        xmlPayload.append(L"<text>");
        xmlPayload.append(m_text);
        xmlPayload.append(L"</text>");

        return hstring(xmlPayload);
    }
}

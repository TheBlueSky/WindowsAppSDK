#include "pch.h"
#include "NFText.h"
#include "Microsoft.Windows.PushNotifications.NFText.g.cpp"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{

    NFText::NFText(hstring text)
    {
        m_text = text;
    }

    hstring NFText::GetXml()
    {
        std::wstring xmlPayload{ L"" };

        xmlPayload.append(L"<text>");
        xmlPayload.append(m_text);
        xmlPayload.append(L"</text>");

        return hstring(xmlPayload);
    }
}

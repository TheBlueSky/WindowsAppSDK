#include "pch.h"
#include "Text.h"
#include "Microsoft.Windows.PushNotifications.Text.g.cpp"

using namespace winrt::Windows::Data::Xml::Dom;

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{

    Text::Text(hstring text)
    {
        m_text = text;
    }

    hstring Text::GetXml()
    {
        return hstring(m_text);
    }
}

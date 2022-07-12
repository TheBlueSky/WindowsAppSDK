#include "pch.h"
#include "AppNotificationContent.h"
#include "Microsoft.Windows.PushNotifications.AppNotificationContent.g.cpp"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    AppNotificationContent::AppNotificationContent()
    {
    }

    // Adds arguments to the launch attribute to return when AppNotification is clicked.
    winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AppNotificationContent::AddArgument(hstring key, hstring value)
    {
        m_key = key;
        m_value = value;

        return *this;
    }

    // Adds text to the AppNotification.
    winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AppNotificationContent::AddText(hstring text)
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

        return *this;
    }

    winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AppNotificationContent::AddText(hstring text, AppNotificationTextProperties properties)
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

        return *this;
    }

    winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AppNotificationContent::SetAttributionText(hstring text)
    {
        return *this;
    }

    winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AppNotificationContent::SetAttributionText(hstring text, hstring language)
    {
        return *this;
    }

    // Sets the full-width inline-image that appears when you expand the AppNotification
    winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AppNotificationContent::SetInlineImage(winrt::Windows::Foundation::Uri imageUri)
    {
        m_imageUri = imageUri;
        return *this;
    }

    winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AppNotificationContent::SetInlineImage(winrt::Windows::Foundation::Uri imageUri, hstring alternateText)
    {
        m_imageUri = imageUri;

        return *this;
    }

    winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AppNotificationContent::SetInlineImage(winrt::Windows::Foundation::Uri imageUri, bool useCircleCrop)
    {
        m_imageUri = imageUri;
        m_useCircleCrop = useCircleCrop;

        return *this;
    }

    winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AppNotificationContent::SetInlineImage(winrt::Windows::Foundation::Uri imageUri, hstring alternateText, bool useCircleCrop)
    {
        m_imageUri = imageUri;
        m_useCircleCrop = useCircleCrop;

        return *this;
    }

    // Sets the image that is left-aligned with notification text
    winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AppNotificationContent::SetAppLogoOverrideImage(winrt::Windows::Foundation::Uri imageUri)
    {
        m_imageUri = imageUri;

        return *this;
    }

    winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AppNotificationContent::SetAppLogoOverrideImage(winrt::Windows::Foundation::Uri imageUri, hstring alternateText)
    {
        m_imageUri = imageUri;

        return *this;
    }

    winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AppNotificationContent::SetAppLogoOverrideImage(winrt::Windows::Foundation::Uri imageUri, bool useCircleCrop)
    {
        m_imageUri = imageUri;
        m_useCircleCrop = useCircleCrop;

        return *this;
    }

    winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AppNotificationContent::SetAppLogoOverrideImage(winrt::Windows::Foundation::Uri imageUri, hstring alternateText, bool useCircleCrop)
    {
        m_imageUri = imageUri;
        m_useCircleCrop = useCircleCrop;

        return *this;
    }

    // Sets the image that displays within the banner of the AppNotification.
    winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AppNotificationContent::SetHeroImage(winrt::Windows::Foundation::Uri imageUri)
    {
        m_imageUri = imageUri;

        return *this;
    }

    winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AppNotificationContent::SetHeroImage(winrt::Windows::Foundation::Uri imageUri, hstring alternateText)
    {
        m_imageUri = imageUri;

        return *this;
    }

    // Add an input textbox to retrieve user input.
    winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AppNotificationContent::AddTextBox(hstring id)
    {
        return *this;
    }

    winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AppNotificationContent::AddTextBox(hstring id, hstring placeHolderText, hstring title)
    {
        return *this;
    }

    // Adds a button to the AppNotificationContent
    winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AppNotificationContent::AddButton(AppNotificationButton button)
    {
        m_button = button;

        return *this;
    }

    // Retrieves the notification XML content so that it can be used with a local
    // AppNotification constructor.
    hstring AppNotificationContent::GetXml()
    {
        std::wstring xmlPayload{ L"" };

        xmlPayload.append(L"<toast launch = \"" + m_key + L"=" + m_value + L"\">");

        xmlPayload.append(L"<visual>");
        xmlPayload.append(L"<binding template = \"ToastGeneric\">");

        xmlPayload.append(GetImageXml());

        if (m_lines > 0)
        {
            xmlPayload.append(BuildTextXml(m_text1));
        }

        if (m_lines > 1)
        {
            xmlPayload.append(BuildTextXml(m_text2));
        }

        xmlPayload.append(L"</binding>");
        xmlPayload.append(L"</visual>");

        xmlPayload.append(m_button.GetXml());

        xmlPayload.append(L"</toast>");

        return hstring(xmlPayload);
    }

    hstring AppNotificationContent::GetImageXml()
    {
        std::wstring xmlPayload{ L"" };

        xmlPayload.append(L"<image ");
#if 0
        switch (m_placement)
        {
        case ImagePlacement::Inline:
            xmlPayload.append(L"placement = \"inline\" ");
            break;

        case ImagePlacement::AppLogoOverride:
#endif
            xmlPayload.append(L"placement = \"appLogoOverride\" ");
#if 0
            break;

        case ImagePlacement::Hero:
            xmlPayload.append(L"placement = \"hero\" ");
            break;

        default: // don't specify placement
            break;
        }
#endif
        if (m_useCircleCrop)
        {
            xmlPayload.append(L"hint - crop = \"circle\" ");

        }

        xmlPayload.append(L"src = \"" + m_imageUri.ToString() + L"\"/>");

        return hstring(xmlPayload);
    }

    hstring AppNotificationContent::BuildTextXml(std::wstring text)
    {
        std::wstring xmlPayload{ L"" };

        xmlPayload.append(L"<text>");
        xmlPayload.append(text);
        xmlPayload.append(L"</text>");

        return hstring(xmlPayload);
    }
}

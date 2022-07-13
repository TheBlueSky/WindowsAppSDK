#include "pch.h"
#include "NFAppNotificationContent.h"
#include "Microsoft.Windows.PushNotifications.NFAppNotificationContent.g.cpp"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    NFAppNotificationContent::NFAppNotificationContent()
    {
    }

    // Adds arguments to the launch attribute to return when AppNotification is clicked.
    void NFAppNotificationContent::AddArgument(hstring key, hstring value)
    {
        m_key = key;
        m_value = value;
    }

    // Adds text to the AppNotification.
    void NFAppNotificationContent::AddText(hstring text)
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
    }

    void NFAppNotificationContent::AddText(hstring text, NFAppNotificationTextProperties properties)
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
    }

    void NFAppNotificationContent::SetAttributionText(hstring text)
    {
    }

    void NFAppNotificationContent::SetAttributionText(hstring text, hstring language)
    {
    }

    // Sets the full-width inline-image that appears when you expand the AppNotification
    void NFAppNotificationContent::SetInlineImage(winrt::Windows::Foundation::Uri imageUri)
    {
        m_imageUri = imageUri;
    }

    void NFAppNotificationContent::SetInlineImage(winrt::Windows::Foundation::Uri imageUri, hstring alternateText)
    {
        m_imageUri = imageUri;
    }

    void NFAppNotificationContent::SetInlineImage(winrt::Windows::Foundation::Uri imageUri, bool useCircleCrop)
    {
        m_imageUri = imageUri;
        m_useCircleCrop = useCircleCrop;
    }

    void NFAppNotificationContent::SetInlineImage(winrt::Windows::Foundation::Uri imageUri, hstring alternateText, bool useCircleCrop)
    {
        m_imageUri = imageUri;
        m_useCircleCrop = useCircleCrop;
    }

    // Sets the image that is left-aligned with notification text
    void NFAppNotificationContent::SetAppLogoOverrideImage(winrt::Windows::Foundation::Uri imageUri)
    {
        m_imageUri = imageUri;
    }

    void NFAppNotificationContent::SetAppLogoOverrideImage(winrt::Windows::Foundation::Uri imageUri, hstring alternateText)
    {
        m_imageUri = imageUri;
    }

    void NFAppNotificationContent::SetAppLogoOverrideImage(winrt::Windows::Foundation::Uri imageUri, bool useCircleCrop)
    {
        m_imageUri = imageUri;
        m_useCircleCrop = useCircleCrop;
    }

    void NFAppNotificationContent::SetAppLogoOverrideImage(winrt::Windows::Foundation::Uri imageUri, hstring alternateText, bool useCircleCrop)
    {
        m_imageUri = imageUri;
        m_useCircleCrop = useCircleCrop;
    }

    // Sets the image that displays within the banner of the AppNotification.
    void NFAppNotificationContent::SetHeroImage(winrt::Windows::Foundation::Uri imageUri)
    {
        m_imageUri = imageUri;
    }

    void NFAppNotificationContent::SetHeroImage(winrt::Windows::Foundation::Uri imageUri, hstring alternateText)
    {
        m_imageUri = imageUri;
    }

    // Add an input textbox to retrieve user input.
    void NFAppNotificationContent::AddTextBox(hstring id)
    {
    }

    void NFAppNotificationContent::AddTextBox(hstring id, hstring placeHolderText, hstring title)
    {
    }

    // Adds a button to the AppNotificationContent
    void NFAppNotificationContent::AddButton(NFAppNotificationButton button)
    {
        m_button = button;
    }

    // Retrieves the notification XML content so that it can be used with a local
    // AppNotification constructor.
    hstring NFAppNotificationContent::GetXml()
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

    hstring NFAppNotificationContent::GetImageXml()
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

    hstring NFAppNotificationContent::BuildTextXml(std::wstring text)
    {
        std::wstring xmlPayload{ L"" };

        xmlPayload.append(L"<text>");
        xmlPayload.append(text);
        xmlPayload.append(L"</text>");

        return hstring(xmlPayload);
    }
}

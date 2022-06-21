#include "pch.h"
#include "Image.h"
#include "Microsoft.Windows.PushNotifications.Image.g.cpp"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{

    Image::Image(hstring imageSrc)
    {
        m_imageSrc = imageSrc;
    }

    winrt::Microsoft::Windows::PushNotifications::Image Image::SetUsesCircleCrop(bool usesCircleCrop)
    {
        m_usesCircleCrop = usesCircleCrop;

        return *this;
    }

    winrt::Microsoft::Windows::PushNotifications::Image Image::SetImagePlacement(ImagePlacement placement)
    {
        m_placement = placement;

        return *this;
    }

    hstring Image::GetXml()
    {
        std::wstring xmlPayload{ L"" };

        xmlPayload.append(L"<image ");

        switch (m_placement)
        {
            case ImagePlacement::Inline:
                xmlPayload.append(L"placement = \"inline\" ");
                break;

            case ImagePlacement::AppLogoOverride:
                xmlPayload.append(L"placement = \"appLogoOverride\" ");
                break;

            case ImagePlacement::Hero:
                xmlPayload.append(L"placement = \"hero\" ");
                break;

            default: // don't specify placement
                break;
        }

        if (m_usesCircleCrop)
        {
            xmlPayload.append(L"hint - crop = \"circle\" ");

        }

        xmlPayload.append(L"src = \"" + m_imageSrc + L"\"/>");

        return hstring(xmlPayload);
    }
}

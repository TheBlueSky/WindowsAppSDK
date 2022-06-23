#include "pch.h"
#include "NFImage.h"
#include "Microsoft.Windows.PushNotifications.NFImage.g.cpp"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{

    NFImage::NFImage(hstring imageSrc)
    {
        m_imageSrc = imageSrc;
    }

    void NFImage::SetUsesCircleCrop(bool usesCircleCrop)
    {
        m_usesCircleCrop = usesCircleCrop;
    }

    void NFImage::SetImagePlacement(ImagePlacement placement)
    {
        m_placement = placement;
    }

    hstring NFImage::GetXml()
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

#pragma once
#include "Microsoft.Windows.PushNotifications.NFImage.g.h"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    struct NFImage : NFImageT<NFImage>
    {
        NFImage(hstring imageSrc);

        // An enum to describe how the image will be cropped.
        void SetUsesCircleCrop(bool usesCircleCrop);

        // Override the app logo with custom image of choice that will be displayed on the AppNotification, otherwise it will be an inline image.
        void SetImagePlacement(ImagePlacement placement);

        // Retrieves the XML content of the image.
        hstring GetXml();

    private:
        std::wstring m_imageSrc{};
        bool m_usesCircleCrop{};
        ImagePlacement m_placement{};
    };
}

namespace winrt::Microsoft::Windows::PushNotifications::factory_implementation
{
    struct NFImage : NFImageT<NFImage, implementation::NFImage>
    {
    };
}

#pragma once
#include "Microsoft.Windows.PushNotifications.Image.g.h"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    struct Image : ImageT<Image>
    {
        Image(hstring imageSrc);

        // An enum to describe how the image will be cropped.
        winrt::Microsoft::Windows::PushNotifications::Image SetUsesCircleCrop(bool usesCircleCrop);

        // Override the app logo with custom image of choice that will be displayed on the AppNotification, otherwise it will be an inline image.
        winrt::Microsoft::Windows::PushNotifications::Image SetImagePlacement(ImagePlacement placement);

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
    struct Image : ImageT<Image, implementation::Image>
    {
    };
}

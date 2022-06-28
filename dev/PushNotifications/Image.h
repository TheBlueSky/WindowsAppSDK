#pragma once
#include "Microsoft.Windows.PushNotifications.Image.g.h"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    struct Image : ImageT<Image>
    {
        Image(winrt::Windows::Foundation::Uri imageUri);

        // An enum to describe how the image will be cropped.
        winrt::Microsoft::Windows::PushNotifications::Image UsesCircleCrop();

        // Override the app logo with custom image of choice that will be displayed on the AppNotification, otherwise it will be an inline image.
        winrt::Microsoft::Windows::PushNotifications::Image SetImagePlacement(ImagePlacement placement);

        // Retrieves the XML content of the image.
        hstring GetXml();

    private:
        winrt::Windows::Foundation::Uri m_imageUri{ L"file://default.png" };
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

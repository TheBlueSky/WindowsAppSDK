#pragma once
#include "Microsoft.Windows.PushNotifications.AppNotificationContent.g.h"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    struct AppNotificationContent : AppNotificationContentT<AppNotificationContent>
    {
        AppNotificationContent();

        // Adds arguments to the launch attribute to return when AppNotification is clicked.
        winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AddArgument(hstring key, hstring value);

        // Adds text to the AppNotification.
        winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AddText(hstring text);
        winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AddText(hstring text, AppNotificationTextProperties properties);
        winrt::Microsoft::Windows::PushNotifications::AppNotificationContent SetAttributionText(hstring text);
        winrt::Microsoft::Windows::PushNotifications::AppNotificationContent SetAttributionText(hstring text, hstring language);

        // Sets the full-width inline-image that appears when you expand the AppNotification
        winrt::Microsoft::Windows::PushNotifications::AppNotificationContent SetInlineImage(winrt::Windows::Foundation::Uri imageUri);
        winrt::Microsoft::Windows::PushNotifications::AppNotificationContent SetInlineImage(winrt::Windows::Foundation::Uri imageUri, hstring alternateText);
        winrt::Microsoft::Windows::PushNotifications::AppNotificationContent SetInlineImage(winrt::Windows::Foundation::Uri imageUri, bool useCircleCrop);
        winrt::Microsoft::Windows::PushNotifications::AppNotificationContent SetInlineImage(winrt::Windows::Foundation::Uri imageUri, hstring alternateText, bool useCircleCrop);

        // Sets the image that is left-aligned with notification text
        winrt::Microsoft::Windows::PushNotifications::AppNotificationContent SetAppLogoOverrideImage(winrt::Windows::Foundation::Uri imageUri);
        winrt::Microsoft::Windows::PushNotifications::AppNotificationContent SetAppLogoOverrideImage(winrt::Windows::Foundation::Uri imageUri, hstring alternateText);
        winrt::Microsoft::Windows::PushNotifications::AppNotificationContent SetAppLogoOverrideImage(winrt::Windows::Foundation::Uri imageUri, bool useCircleCrop);
        winrt::Microsoft::Windows::PushNotifications::AppNotificationContent SetAppLogoOverrideImage(winrt::Windows::Foundation::Uri imageUri, hstring alternateText, bool useCircleCrop);

        // Sets the image that displays within the banner of the AppNotification.
        winrt::Microsoft::Windows::PushNotifications::AppNotificationContent SetHeroImage(winrt::Windows::Foundation::Uri imageUri);
        winrt::Microsoft::Windows::PushNotifications::AppNotificationContent SetHeroImage(winrt::Windows::Foundation::Uri imageUri, hstring alternateText);

        // Add an input textbox to retrieve user input.
        winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AddTextBox(hstring id);
        winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AddTextBox(hstring id, hstring placeHolderText, hstring title);

        // Adds a button to the AppNotificationContent
        winrt::Microsoft::Windows::PushNotifications::AppNotificationContent AddButton(AppNotificationButton button);

        // Retrieves the notification XML content so that it can be used with a local
        // AppNotification constructor.
        hstring GetXml();

    private:
        int m_lines{ 0 };
        std::wstring m_text1{ L"default1" };
        std::wstring m_text2{ L"default2" };
        AppNotificationButton m_button{ L"Default Button" };

        // Image
        winrt::Windows::Foundation::Uri m_imageUri{ L"file://Path/to/default.png" };
        bool m_useCircleCrop{};

        // Argument
        std::wstring m_key{};
        std::wstring m_value{};

        hstring GetImageXml();
        hstring BuildTextXml(std::wstring text);
    };
}
namespace winrt::Microsoft::Windows::PushNotifications::factory_implementation
{
    struct AppNotificationContent : AppNotificationContentT<AppNotificationContent, implementation::AppNotificationContent>
    {
    };
}

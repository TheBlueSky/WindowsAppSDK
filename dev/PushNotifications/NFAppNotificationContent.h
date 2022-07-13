#pragma once
#include "Microsoft.Windows.PushNotifications.NFAppNotificationContent.g.h"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    struct NFAppNotificationContent : NFAppNotificationContentT<NFAppNotificationContent>
    {
        NFAppNotificationContent();

        // Adds arguments to the launch attribute to return when AppNotification is clicked.
        void AddArgument(hstring key, hstring value);

        // Adds text to the AppNotification.
        void AddText(hstring text);
        void AddText(hstring text, NFAppNotificationTextProperties properties);
        void SetAttributionText(hstring text);
        void SetAttributionText(hstring text, hstring language);

        // Sets the full-width inline-image that appears when you expand the AppNotification
        void SetInlineImage(winrt::Windows::Foundation::Uri imageUri);
        void SetInlineImage(winrt::Windows::Foundation::Uri imageUri, hstring alternateText);
        void SetInlineImage(winrt::Windows::Foundation::Uri imageUri, bool useCircleCrop);
        void SetInlineImage(winrt::Windows::Foundation::Uri imageUri, hstring alternateText, bool useCircleCrop);

        // Sets the image that is left-aligned with notification text
        void SetAppLogoOverrideImage(winrt::Windows::Foundation::Uri imageUri);
        void SetAppLogoOverrideImage(winrt::Windows::Foundation::Uri imageUri, hstring alternateText);
        void SetAppLogoOverrideImage(winrt::Windows::Foundation::Uri imageUri, bool useCircleCrop);
        void SetAppLogoOverrideImage(winrt::Windows::Foundation::Uri imageUri, hstring alternateText, bool useCircleCrop);

        // Sets the image that displays within the banner of the AppNotification.
        void SetHeroImage(winrt::Windows::Foundation::Uri imageUri);
        void SetHeroImage(winrt::Windows::Foundation::Uri imageUri, hstring alternateText);

        // Add an input textbox to retrieve user input.
        void AddTextBox(hstring id);
        void AddTextBox(hstring id, hstring placeHolderText, hstring title);

        // Adds a button to the AppNotificationContent
        void AddButton(NFAppNotificationButton button);

        // Retrieves the notification XML content so that it can be used with a local
        // AppNotification constructor.
        hstring GetXml();

    private:
        int m_lines{ 0 };
        std::wstring m_text1{ L"default1" };
        std::wstring m_text2{ L"default2" };
        NFAppNotificationButton m_button{ L"Default Button" };

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
    struct NFAppNotificationContent : NFAppNotificationContentT<NFAppNotificationContent, implementation::NFAppNotificationContent>
    {
    };
}

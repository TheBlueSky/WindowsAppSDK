#pragma once
#include "Microsoft.Windows.PushNotifications.NFAppNotificationContent.g.h"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    struct NFAppNotificationContent : NFAppNotificationContentT<NFAppNotificationContent>
    {
        NFAppNotificationContent() = default;

        void AddArgument(hstring key, hstring value);

        void AddButton(NFButton button);
        void AddImage(NFImage image);
        void AddText(NFText text);

        hstring GetXml();

    private:
        int m_lines{ 0 };
        NFText m_text1{ L"default1" };
        NFText m_text2{ L"default2" };
        NFButton m_button{ L"Default Button" };
        NFImage m_image{ L"DefaultImage" };
        std::wstring m_key{};
        std::wstring m_value{};
    };
}
namespace winrt::Microsoft::Windows::PushNotifications::factory_implementation
{
    struct NFAppNotificationContent : NFAppNotificationContentT<NFAppNotificationContent, implementation::NFAppNotificationContent>
    {
    };
}

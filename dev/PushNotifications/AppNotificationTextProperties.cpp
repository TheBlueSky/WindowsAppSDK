#include "pch.h"
#include "AppNotificationTextProperties.h"
#include "Microsoft.Windows.PushNotifications.AppNotificationTextProperties.g.cpp"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{

    winrt::Microsoft::Windows::PushNotifications::AppNotificationTextProperties AppNotificationTextProperties::SetLanguage(hstring language)
    {
        return *this;
    }

    winrt::Microsoft::Windows::PushNotifications::AppNotificationTextProperties AppNotificationTextProperties::UsesCallScenarioAlign()
    {
        return *this;
    }

    winrt::Microsoft::Windows::PushNotifications::AppNotificationTextProperties AppNotificationTextProperties::SetMaxLines(int maxLines)
    {
        return *this;
    }
}

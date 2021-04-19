﻿#pragma once
#include "Microsoft.Windows.PushNotifications.PushNotificationChannel.g.h"

namespace winrt::Microsoft::Windows::PushNotifications::implementation
{
    struct PushNotificationChannel : PushNotificationChannelT<PushNotificationChannel>
    {
        PushNotificationChannel() = default;

        PushNotificationChannel(winrt::Windows::Networking::PushNotifications::PushNotificationChannel const& channel);
        winrt::Windows::Foundation::Uri Uri();
        winrt::Windows::Foundation::DateTime ExpirationTime();
        void Close();

        winrt::event_token PushReceived(winrt::Windows::Foundation::TypedEventHandler<Microsoft::Windows::PushNotifications::PushNotificationChannel, Microsoft::Windows::PushNotifications::PushNotificationReceivedEventArgs> const& handler);
        void PushReceived(winrt::event_token const& token) noexcept;

    private:
        void LambdaWrapper(
            winrt::Windows::Networking::PushNotifications::PushNotificationChannel /*channel*/,
            winrt::Windows::Networking::PushNotifications::PushNotificationReceivedEventArgs args);

        winrt::Windows::Networking::PushNotifications::PushNotificationChannel m_channel{ nullptr };

        wil::critical_section m_lock;
    };
}
namespace winrt::Microsoft::Windows::PushNotifications::factory_implementation
{
    struct PushNotificationChannel : PushNotificationChannelT<PushNotificationChannel, implementation::PushNotificationChannel>
    {
    };
}

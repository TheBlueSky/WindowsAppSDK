// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#pragma once
#include "pch.h"

ToastRegistrationManager::ToastRegistrationManager()
{
    m_toastStorage = winrt::Windows::Storage::ApplicationData::Current().LocalSettings().CreateContainer(
        L"Toast", winrt::Windows::Storage::ApplicationDataCreateDisposition::Always);

    for (auto pair : m_toastStorage.Values())
    {
        Add(pair.Key().c_str(), pair.Value().as<winrt::hstring>().c_str());
    }
}

void ToastRegistrationManager::Add(std::wstring const& processName, std::wstring const& toastAppId)
{
    auto lock = m_lock.lock_exclusive();
    m_registrationMap[processName] = toastAppId;

    m_toastStorage.Values().Insert(processName, winrt::box_value(toastAppId));
}

void ToastRegistrationManager::Remove(std::wstring const& processName)
{
    auto lock = m_lock.lock_exclusive();
    m_registrationMap.erase(processName);

    m_toastStorage.Values().Remove(processName);
}

std::wstring ToastRegistrationManager::GetToastRegistration(std::wstring const& processName)
{
    auto lock = m_lock.lock_shared();
    return m_registrationMap[processName];
}

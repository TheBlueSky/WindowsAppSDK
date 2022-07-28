// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#include "pch.h"
#include "$safeitemname$.h"
#if __has_include("$safeitemname$.g.cpp")
#include "$safeitemname$.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::$rootnamespace$::implementation
{
    $safeitemname$::$safeitemname$()
    {
        DefaultStyleKey(winrt::box_value(L"$rootnamespace$.$safeitemname$"));
    }

    int32_t $safeitemname$::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void $safeitemname$::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
}

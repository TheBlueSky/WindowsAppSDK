// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#include "pch.h"
#include "Microsoft.Test.DynamicDependency.Widgets.Widget2.h"
#include "Microsoft.Test.DynamicDependency.Widgets.Widget2.g.cpp"

#include "Microsoft.Test.DynamicDependency.Widgets.Widget1.h"

namespace winrt::Microsoft::Test::DynamicDependency::Widgets::implementation
{
    winrt::Microsoft::Test::DynamicDependency::Widgets::Widget1 Widget2::GetStaticWidget1()
    {
        static winrt::Microsoft::Test::DynamicDependency::Widgets::Widget1 widget1;
        return widget1;
    }
    winrt::Microsoft::Test::DynamicDependency::Widgets::Widget1 Widget2::GetWidget1()
    {
        winrt::Microsoft::Test::DynamicDependency::Widgets::Widget1 widget1;
        return widget1;
        //return winrt::make<implementation::Widget1>();
    }
}

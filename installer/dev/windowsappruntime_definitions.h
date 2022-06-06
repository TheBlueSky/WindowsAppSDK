﻿// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#pragma once

// This header defines the packages included in the installer.
// By default, the project will use test packages built for verification of this installer.

// For building the installer with non-test packages, include a "windowsappruntime_definitions_override.h" file.
// If present, the override header will be loaded to change the package definitions such as the path.
// Preprocessor definitions used in the override header must be supported by the resource compiler.

// Override header file example:
//
// #pragma once
//
// #undef MSIX_FRAMEWORK_X86_PATH
// #define MSIX_FRAMEWORK_X86_PATH "custompackages\\my_custom_x86_framework.appx"
//

// Each package has a package definition listed below.
// Names for macros are intentionally kept short due to resource compiler length limitations.

// x86 Framework
#define MSIX_FRAMEWORK_X86_ID L"MSIX_FWPACKAGE_X86"
#define MSIX_FRAMEWORK_X86_RCID MSIX_FWPACKAGE_X86
#define MSIX_FRAMEWORK_X86_TYPE L"PACKAGE"
#define MSIX_FRAMEWORK_X86_RCTYPE PACKAGE
#define MSIX_FRAMEWORK_X86_BEHAVIOR DeploymentBehavior::Default
#ifndef MSIX_FRAMEWORK_X86_PATH
    #define MSIX_FRAMEWORK_X86_PATH "..\\test\\testpackages\\framework_x86.msix"
#endif

// x64 Framework
#define MSIX_FRAMEWORK_X64_ID L"MSIX_FWPACKAGE_X64"
#define MSIX_FRAMEWORK_X64_RCID MSIX_FWPACKAGE_X64
#define MSIX_FRAMEWORK_X64_TYPE L"PACKAGE"
#define MSIX_FRAMEWORK_X64_RCTYPE PACKAGE
#define MSIX_FRAMEWORK_X64_BEHAVIOR DeploymentBehavior::Default
#ifndef MSIX_FRAMEWORK_X64_PATH
    #define MSIX_FRAMEWORK_X64_PATH "..\\test\\testpackages\\framework_x64.msix"
#endif

// arm64 Framework
#define MSIX_FRAMEWORK_ARM64_ID L"MSIX_FWPACKAGE_ARM64"
#define MSIX_FRAMEWORK_ARM64_RCID MSIX_FWPACKAGE_ARM64
#define MSIX_FRAMEWORK_ARM64_TYPE L"PACKAGE"
#define MSIX_FRAMEWORK_ARM64_RCTYPE PACKAGE
#define MSIX_FRAMEWORK_ARM64_BEHAVIOR DeploymentBehavior::Default
#ifndef MSIX_FRAMEWORK_ARM64_PATH
    #define MSIX_FRAMEWORK_ARM64_PATH "..\\test\\testpackages\\framework_arm64.msix"
#endif

// x86 Main
#define MSIX_MAIN_X86_ID L"MSIX_MAINPACKAGE_X86"
#define MSIX_MAIN_X86_RCID MSIX_MAINPACKAGE_X86
#define MSIX_MAIN_X86_TYPE L"PACKAGE"
#define MSIX_MAIN_X86_RCTYPE PACKAGE
#define MSIX_MAIN_X86_BEHAVIOR DeploymentBehavior::Default
#ifndef MSIX_MAIN_X86_PATH
    #define MSIX_MAIN_X86_PATH "..\\test\\testpackages\\main_x86.msix"
#endif

// x64 Main
#define MSIX_MAIN_X64_ID L"MSIX_MAINPACKAGE_X64"
#define MSIX_MAIN_X64_RCID MSIX_MAINPACKAGE_X64
#define MSIX_MAIN_X64_TYPE L"PACKAGE"
#define MSIX_MAIN_X64_RCTYPE PACKAGE
#define MSIX_MAIN_X64_BEHAVIOR DeploymentBehavior::Default
#ifndef MSIX_MAIN_X64_PATH
    #define MSIX_MAIN_X64_PATH "..\\test\\testpackages\\main_x64.msix"
#endif

// arm64 Main
#define MSIX_MAIN_ARM64_ID L"MSIX_MAINPACKAGE_ARM64"
#define MSIX_MAIN_ARM64_RCID MSIX_MAINPACKAGE_ARM64
#define MSIX_MAIN_ARM64_TYPE L"PACKAGE"
#define MSIX_MAIN_ARM64_RCTYPE PACKAGE
#define MSIX_MAIN_ARM64_BEHAVIOR DeploymentBehavior::Default
#ifndef MSIX_MAIN_ARM64_PATH
    #define MSIX_MAIN_ARM64_PATH "..\\test\\testpackages\\main_arm64.msix"
#endif

// license Main
#define MSIX_MAIN_LICENSE_ID L"MSIX_MAINPACKAGE_LICENSE"
#define MSIX_MAIN_LICENSE_RCID MSIX_MAINPACKAGE_LICENSE
#define MSIX_MAIN_LICENSE_TYPE L"LICENSE"
#define MSIX_MAIN_LICENSE_RCTYPE LICENSE
#ifndef MSIX_MAIN_LICENSE_PATH
    #define MSIX_MAIN_LICENSE_PATH "..\\test\\testpackages\\main_license.xml"
#endif

// x86 Singleton
#define MSIX_SINGLETON_X86_ID L"MSIX_SINGLETONPACKAGE_X86"
#define MSIX_SINGLETON_X86_RCID MSIX_SINGLETONPACKAGE_X86
#define MSIX_SINGLETON_X86_TYPE L"PACKAGE"
#define MSIX_SINGLETON_X86_RCTYPE PACKAGE
#define MSIX_SINGLETON_X86_BEHAVIOR DeploymentBehavior::Default
#ifndef MSIX_SINGLETON_X86_PATH
    #define MSIX_SINGLETON_X86_PATH "..\\test\\testpackages\\singleton_x86.msix"
#endif

// x64 Singleton
#define MSIX_SINGLETON_X64_ID L"MSIX_SINGLETONPACKAGE_X64"
#define MSIX_SINGLETON_X64_RCID MSIX_SINGLETONPACKAGE_X64
#define MSIX_SINGLETON_X64_TYPE L"PACKAGE"
#define MSIX_SINGLETON_X64_RCTYPE PACKAGE
#define MSIX_SINGLETON_X64_BEHAVIOR DeploymentBehavior::Default
#ifndef MSIX_SINGLETON_X64_PATH
    #define MSIX_SINGLETON_X64_PATH "..\\test\\testpackages\\singleton_x64.msix"
#endif

// arm64 Singleton
#define MSIX_SINGLETON_ARM64_ID L"MSIX_SINGLETONPACKAGE_ARM64"
#define MSIX_SINGLETON_ARM64_RCID MSIX_SINGLETONPACKAGE_ARM64
#define MSIX_SINGLETON_ARM64_TYPE L"PACKAGE"
#define MSIX_SINGLETON_ARM64_RCTYPE PACKAGE
#define MSIX_SINGLETON_ARM64_BEHAVIOR DeploymentBehavior::Default
#ifndef MSIX_SINGLETON_ARM64_PATH
    #define MSIX_SINGLETON_ARM64_PATH "..\\test\\testpackages\\singleton_arm64.msix"
#endif

// license Singleton
#define MSIX_SINGLETON_LICENSE_ID L"MSIX_SINGLETONPACKAGE_LICENSE"
#define MSIX_SINGLETON_LICENSE_RCID MSIX_SINGLETONPACKAGE_LICENSE
#define MSIX_SINGLETON_LICENSE_TYPE L"LICENSE"
#define MSIX_SINGLETON_LICENSE_RCTYPE LICENSE
#ifndef MSIX_SINGLETON_LICENSE_PATH
    #define MSIX_SINGLETON_LICENSE_PATH "..\\test\\testpackages\\singleton_license.xml"
#endif

// x86 DDLM
#define MSIX_DDLM_X86_ID L"MSIX_DDLMPACKAGE_X86"
#define MSIX_DDLM_X86_RCID MSIX_DDLMPACKAGE_X86
#define MSIX_DDLM_X86_TYPE L"PACKAGE"
#define MSIX_DDLM_X86_RCTYPE PACKAGE
#define MSIX_DDLM_X86_BEHAVIOR DeploymentBehavior::Framework
#ifndef MSIX_DDLM_X86_PATH
    #define MSIX_DDLM_X86_PATH "..\\test\\testpackages\\ddlm_x86.msix"
#endif

// x64 DDLM
#define MSIX_DDLM_X64_ID L"MSIX_DDLMPACKAGE_X64"
#define MSIX_DDLM_X64_RCID MSIX_DDLMPACKAGE_X64
#define MSIX_DDLM_X64_TYPE L"PACKAGE"
#define MSIX_DDLM_X64_RCTYPE PACKAGE
#define MSIX_DDLM_X64_BEHAVIOR DeploymentBehavior::Framework
#ifndef MSIX_DDLM_X64_PATH
    #define MSIX_DDLM_X64_PATH "..\\test\\testpackages\\ddlm_x64.msix"
#endif

// arm64 DDLM
#define MSIX_DDLM_ARM64_ID L"MSIX_DDLMPACKAGE_ARM64"
#define MSIX_DDLM_ARM64_RCID MSIX_DDLMPACKAGE_ARM64
#define MSIX_DDLM_ARM64_TYPE L"PACKAGE"
#define MSIX_DDLM_ARM64_RCTYPE PACKAGE
#define MSIX_DDLM_ARM64_BEHAVIOR DeploymentBehavior::Framework
#ifndef MSIX_DDLM_ARM64_PATH
    #define MSIX_DDLM_ARM64_PATH "..\\test\\testpackages\\ddlm_arm64.msix"
#endif


// Package Inclusion
// Each package has a package list entry which defines its inclusion in packages.h and the .rc script.
// To not include a package, undefine the *_LISTENTRY and *_RCENTRY entries. At least one package must be included.

#define MSIX_FRAMEWORK_X86_LISTENTRY { MSIX_FRAMEWORK_X86_ID, MSIX_FRAMEWORK_X86_TYPE, MSIX_FRAMEWORK_X86_BEHAVIOR },
#define MSIX_FRAMEWORK_X86_RCENTRY MSIX_FRAMEWORK_X86_RCID MSIX_FRAMEWORK_X86_RCTYPE MSIX_FRAMEWORK_X86_PATH

#define MSIX_FRAMEWORK_X64_LISTENTRY  { MSIX_FRAMEWORK_X64_ID, MSIX_FRAMEWORK_X64_TYPE, MSIX_FRAMEWORK_X64_BEHAVIOR },
#define MSIX_FRAMEWORK_X64_RCENTRY MSIX_FRAMEWORK_X64_RCID MSIX_FRAMEWORK_X64_RCTYPE MSIX_FRAMEWORK_X64_PATH

#define MSIX_FRAMEWORK_ARM64_LISTENTRY { MSIX_FRAMEWORK_ARM64_ID, MSIX_FRAMEWORK_ARM64_TYPE, MSIX_FRAMEWORK_ARM64_BEHAVIOR },
#define MSIX_FRAMEWORK_ARM64_RCENTRY MSIX_FRAMEWORK_ARM64_RCID MSIX_FRAMEWORK_ARM64_RCTYPE MSIX_FRAMEWORK_ARM64_PATH

#define MSIX_MAIN_X86_LISTENTRY { MSIX_MAIN_X86_ID, MSIX_MAIN_X86_TYPE, MSIX_MAIN_X86_BEHAVIOR },
#define MSIX_MAIN_X86_RCENTRY MSIX_MAIN_X86_RCID MSIX_MAIN_X86_RCTYPE MSIX_MAIN_X86_PATH

#define MSIX_MAIN_X64_LISTENTRY  { MSIX_MAIN_X64_ID, MSIX_MAIN_X64_TYPE, MSIX_MAIN_X64_BEHAVIOR },
#define MSIX_MAIN_X64_RCENTRY MSIX_MAIN_X64_RCID MSIX_MAIN_X64_RCTYPE MSIX_MAIN_X64_PATH

#define MSIX_MAIN_ARM64_LISTENTRY { MSIX_MAIN_ARM64_ID, MSIX_MAIN_ARM64_TYPE, MSIX_MAIN_ARM64_BEHAVIOR },
#define MSIX_MAIN_ARM64_RCENTRY MSIX_MAIN_ARM64_RCID MSIX_MAIN_ARM64_RCTYPE MSIX_MAIN_ARM64_PATH

#define MSIX_SINGLETON_X86_LISTENTRY { MSIX_SINGLETON_X86_ID, MSIX_SINGLETON_X86_TYPE, MSIX_SINGLETON_X86_BEHAVIOR },
#define MSIX_SINGLETON_X86_RCENTRY MSIX_SINGLETON_X86_RCID MSIX_SINGLETON_X86_RCTYPE MSIX_SINGLETON_X86_PATH

#define MSIX_SINGLETON_X64_LISTENTRY  { MSIX_SINGLETON_X64_ID, MSIX_SINGLETON_X64_TYPE, MSIX_SINGLETON_X64_BEHAVIOR },
#define MSIX_SINGLETON_X64_RCENTRY MSIX_SINGLETON_X64_RCID MSIX_SINGLETON_X64_RCTYPE MSIX_SINGLETON_X64_PATH

#define MSIX_SINGLETON_ARM64_LISTENTRY { MSIX_SINGLETON_ARM64_ID, MSIX_SINGLETON_ARM64_TYPE, MSIX_SINGLETON_ARM64_BEHAVIOR },
#define MSIX_SINGLETON_ARM64_RCENTRY MSIX_SINGLETON_ARM64_RCID MSIX_SINGLETON_ARM64_RCTYPE MSIX_SINGLETON_ARM64_PATH

#define MSIX_DDLM_X86_LISTENTRY { MSIX_DDLM_X86_ID, MSIX_DDLM_X86_TYPE, MSIX_DDLM_X86_BEHAVIOR },
#define MSIX_DDLM_X86_RCENTRY MSIX_DDLM_X86_RCID MSIX_DDLM_X86_RCTYPE MSIX_DDLM_X86_PATH

#define MSIX_DDLM_X64_LISTENTRY  { MSIX_DDLM_X64_ID, MSIX_DDLM_X64_TYPE, MSIX_DDLM_X64_BEHAVIOR },
#define MSIX_DDLM_X64_RCENTRY MSIX_DDLM_X64_RCID MSIX_DDLM_X64_RCTYPE MSIX_DDLM_X64_PATH

#define MSIX_DDLM_ARM64_LISTENTRY { MSIX_DDLM_ARM64_ID, MSIX_DDLM_ARM64_TYPE, MSIX_DDLM_ARM64_BEHAVIOR },
#define MSIX_DDLM_ARM64_RCENTRY MSIX_DDLM_ARM64_RCID MSIX_DDLM_ARM64_RCTYPE MSIX_DDLM_ARM64_PATH

// License Inclusion

// NOTE: We default to assuming a Main license file and no Singleton license file for inner-loop purposes.
//       The build pipeline will define expected values in windowsappruntime_definitions_override.h for official builds.

#define MSIX_MAIN_LICENSE_LISTENTRY { MSIX_MAIN_LICENSE_ID, MSIX_MAIN_LICENSE_TYPE },
#define MSIX_MAIN_LICENSE_RCENTRY MSIX_MAIN_LICENSE_RCID MSIX_MAIN_LICENSE_RCTYPE MSIX_MAIN_LICENSE_PATH

#undef MSIX_SINGLETON_LICENSE_LISTENTRY
#undef MSIX_SINGLETON_LICENSE_RCENTRY


// This is defined in the vcxproj based on existence of the header in the same directory.
// It is defined in both the c compiler preprocessor definitions and the resource compiler preprocessor definitions.
#ifdef USE_DEFINITIONS_OVERRIDE_HEADER
    #include "windowsappruntime_definitions_override.h"
#endif

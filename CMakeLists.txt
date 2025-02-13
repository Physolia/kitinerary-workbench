# SPDX-FileCopyrightText: 2018-2021 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.16)
project(kitinerary-workbench VERSION 0.0.1)

find_package(ECM 5.85 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

include(KDECompilerSettings NO_POLICY_SCOPE)
include(ECMAddTests)
include(ECMQtDeclareLoggingCategory)
include(ECMSetupVersion)
include(FeatureSummary)
include(KDEInstallDirs)
include(KDECMakeSettings)

if (QT_MAJOR_VERSION EQUAL "6")
    set(KF_MAJOR_VERSION "6")
else()
    set(KF_MAJOR_VERSION "5")
endif()

set(CMAKE_AUTOUIC ON)
ecm_setup_version(PROJECT VARIABLE_PREFIX KITINERARY_WORKBENCH VERSION_HEADER kitinerary_workbench_version.h)

find_package(Qt${QT_MAJOR_VERSION} REQUIRED COMPONENTS Widgets)
if (QT_MAJOR_VERSION EQUAL "6")
    find_package(Qt6 REQUIRED COMPONENTS Core5Compat)
endif()
find_package(KF${KF_MAJOR_VERSION} REQUIRED COMPONENTS TextEditor KIO)
find_package(KPim${KF_MAJOR_VERSION}PkPass REQUIRED)
find_package(KPim${KF_MAJOR_VERSION}Itinerary 5.24.42 REQUIRED)

add_subdirectory(src)

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)

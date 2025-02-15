cmake_minimum_required(VERSION 3.31)

project(CRQuestionMdBuilder VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

set(PROJECT_SOURCES
        main.cpp
        WidgetExtensions/createNamedQTWidget.h
        CrMdBuilderModel.h
        CrMdBuilderModel.cpp
        MainDialogErrorCode.h
        MainDialog.h
        MainDialog.cpp
        WidgetExtensions/DirectoryLineEdit.h
        WidgetExtensions/NumericLineEdit.h
        SignalRouterController.h
        SignalRouterController.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CRQuestionMdBuilder
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET CRQuestionMdBuilder APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(CRQuestionMdBuilder SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(CRQuestionMdBuilder
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(CRQuestionMdBuilder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/WidgetExtensions)

target_link_libraries(CRQuestionMdBuilder PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(CRQuestionMdBuilder PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CRQuestionMdBuilder)
endif()

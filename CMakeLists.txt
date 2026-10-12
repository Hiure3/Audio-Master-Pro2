cmake_minimum_required(VERSION 3.22)
project(AudioMasterPro VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

# JUCE fixado em uma tag para builds reproduzíveis
FetchContent_Declare(JUCE
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG        8.0.4
    GIT_SHALLOW    ON)

# Catch2 (framework de testes)
FetchContent_Declare(Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.5.4
    GIT_SHALLOW    ON)

FetchContent_MakeAvailable(JUCE Catch2)

# ---------------------------------------------------------------
# AMP_Core: nucleo (DSP, metering, engine). Sem UI.
# Nesta etapa so tem utilitarios header-only (INTERFACE).
# Sera transformada em biblioteca STATIC quando houver .cpp.
# ---------------------------------------------------------------
add_library(AMP_Core INTERFACE)
target_include_directories(AMP_Core INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Source)
target_compile_features(AMP_Core INTERFACE cxx_std_20)

# ---------------------------------------------------------------
# Aplicativo Standalone
# ---------------------------------------------------------------
juce_add_gui_app(AudioMasterPro
    PRODUCT_NAME "Audio Master Pro"
    COMPANY_NAME "Audio Master Pro"
    VERSION ${PROJECT_VERSION})

target_sources(AudioMasterPro PRIVATE
    Source/Application/Main.cpp
    Source/UI/MainComponent.cpp
    Source/UI/MainComponent.h)

target_compile_definitions(AudioMasterPro PRIVATE
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_APPLICATION_NAME_STRING="Audio Master Pro"
    JUCE_APPLICATION_VERSION_STRING="${PROJECT_VERSION}")

target_link_libraries(AudioMasterPro
    PRIVATE
        AMP_Core
        juce::juce_gui_basics
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags)

# ---------------------------------------------------------------
# Testes
# ---------------------------------------------------------------
enable_testing()
add_subdirectory(Tests)

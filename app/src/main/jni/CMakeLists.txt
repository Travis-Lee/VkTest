cmake_minimum_required(VERSION 3.4.1)

project(vktuts)



set(SRC_DIR ${CMAKE_SOURCE_DIR})

set(COMMON_DIR ${ANDROID_NDK}/sources/third_party/vulkan/src/common)

add_library(${CMAKE_PROJECT_NAME} SHARED
        g_vulkan.cpp
        ${COMMON_DIR}/vulkan_wrapper.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -std=c++11 -DVK_USE_PLATFORM_ANDROID_KHR")

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    ${COMMON_DIR})

target_link_libraries(${CMAKE_PROJECT_NAME}
    log
    android)

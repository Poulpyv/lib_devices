CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

project(devices)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/device_iostream.cpp
			${CMAKE_CURRENT_SOURCE_DIR}/src/device_udp.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

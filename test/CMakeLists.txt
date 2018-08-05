CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

project(test_devices)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

include_directories(${CMAKE_SOURCE_DIR}/lib/include)
link_directories(${CMAKE_BINARY_DIR}/lib)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} devices)

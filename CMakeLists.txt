cmake_minimum_required(VERSION 3.12)

# Project name and version
project(cpp_console_app_zero VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Boost
find_package(Boost REQUIRED COMPONENTS date_time)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    message(STATUS "Boost found: ${Boost_INCLUDE_DIRS}")
else()
    message(FATAL_ERROR "Boost not found!")
endif()

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/cpp_console_app_zero)

# Add the main executable
add_executable(cpp_console_app_zero cpp_console_app_zero/cpp_console_app_zero.cpp cpp_console_app_zero/gigasecond.cpp)

# Add all source files to the executable
file(GLOB SOURCES cpp_console_app_zero/*.cpp)
target_sources(cpp_console_app_zero PRIVATE ${SOURCES})

# Link Boost libraries
target_link_libraries(cpp_console_app_zero PRIVATE Boost::date_time)

# Link libraries (if using vcpkg or other dependencies, add them here)
# Example: target_link_libraries(cpp_console_app_zero PRIVATE some_library)

# Enable testing
enable_testing()

# Add tests (if applicable)
# Example:
# add_executable(test_runner tests/test_runner.cpp)
# target_link_libraries(test_runner PRIVATE cpp_console_app_zero)
# add_test(NAME test_runner COMMAND test_runner)

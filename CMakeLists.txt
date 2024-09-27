cmake_minimum_required(VERSION 3.8)
project(ndn-simple-test)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define BOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED
add_definitions(-DBOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(NDN_CXX REQUIRED libndn-cxx)

include_directories(${NDN_CXX_INCLUDE_DIRS})
link_directories(${NDN_CXX_LIBRARY_DIRS})

add_executable(producer producer.cpp)
target_link_libraries(producer ${NDN_CXX_LIBRARIES})

add_executable(consumer consumer.cpp)
target_link_libraries(consumer ${NDN_CXX_LIBRARIES})

cmake_minimum_required(VERSION 3.16)

project(telegram_macro C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lcurl -pthread")

find_package(Threads REQUIRED)
find_package(Boost REQUIRED)
find_package(CURL REQUIRED)

set(CURL_LIBRARY "-lcurl")
set(CMAKE_THREAD_LIBS_INIT "-lpthread")

include_directories(
        sj_lib/include
        source
)

link_directories(
        sj_lib/lib
)

file(GLOB _cpp_files "source/*.cpp")

add_executable(telegram_macro
        ${_cpp_files}
        sj_lib/source/util/util.cpp sj_lib/source/util/util.h)

target_link_libraries(telegram_macro
        telegramagent
        xthread
        util
        ${CURL_LIBRARIES}
        )

add_subdirectory(sj_lib/source/util util)
add_subdirectory(sj_lib/source/xthread xthread)
add_subdirectory(sj_lib/source/telegram_agent telegramagent)



cmake_minimum_required(VERSION 3.16)

project(telegram_macro C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lcurl -pthread")

find_package(Threads REQUIRED)
find_package(Boost REQUIRED)
find_package(CURL REQUIRED)
find_package(jsoncpp REQUIRED)

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
   )

target_include_directories(
        telegram_macro PRIVATE ${ICU_INCLUDE_DIR}
)
target_link_libraries(telegram_macro
        ${CURL_LIBRARIES}
        ${BOOST_LIBRARIES}
        ${ICU_LIBRARIES}
        telegramagent
        xthread
        util
        jsoncpp_lib
        )






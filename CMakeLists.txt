cmake_minimum_required(VERSION 3.8)

project(macro C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package (CURL REQUIRED)
#add_compile_definitions(_DEBUG_)
#find_package(Threads REQUIRED)
#find_package(cppzmq REQUIRED)
#find_package(PahoMqttCpp REQUIRED)
#find_package(tinyxml2 CONFIG REQUIRED)
#find_package(Boost REQUIRED)

include_directories(
        ${CURL_INCLUDE_DIR}
        sj_lib/include
        source
)

link_directories(
        sj_lib/lib
)

file(GLOB _cpp_files "source/*.cpp")

add_executable(macro
        ${_cpp_files})

#target_compile_options(${PROJECT_NAME} PUBLIC "-lpthread" "-lcurl")

target_link_libraries(macro
        ${CURL_LIBRARIES}
        xthread
        telegramagent
        )


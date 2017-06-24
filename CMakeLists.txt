cmake_minimum_required(VERSION 3.7)

project(ObjectWrap_Nan)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES main.cpp src/*.cpp src/*.h test/cpp/*.cpp test/cpp/*.h)

include_directories(/usr/local/include ./node_modules/nan)

add_executable(CppClassTest ${SOURCES})

target_link_libraries(CppClassTest /usr/local/lib/libcppunit.a)

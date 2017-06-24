cmake_minimum_required(VERSION 3.7)

project(ObjectWrap_Nan)

include_directories(/usr/local/include ./node_modules/nan)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp test/cpp/BoilerplateTestCase.cpp test/cpp/BoilerplateTestCase.h src/SampleObject.cpp src/SampleObject.h test/cpp/SampleObjectTestCase.cpp test/cpp/SampleObjectTestCase.h)
add_executable(CppClassTest ${SOURCE_FILES})

target_link_libraries(CppClassTest /usr/local/lib/libcppunit.a)

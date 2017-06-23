# TDD of a C++ Addon for NodeJs

This repository provides and example for TDD development
of an Addon that uses NAN and ObjectWrap to expose a C++ 
object to NodeJs.

**Development Environment:** CLion

**Javascript Test Framework:** Mocha / Chai

**Cpp Test Framework:** Cppunit

**Tested On Mac OS 10.12.5**
**Node version 8.1.2**
**Cppunit version:1.14.0**


## Setting up:
* Added a .gitignore 
* Installed cppunit with "brew install cppunit"
* Installed node-gyp with "sudo npm install -g node-gyp"
* In CLion, set the Javascript version to ES6 in preferences, and enabled Node and NPM
* In ./ and ./test/js directories, run npm install.
* Edit CMakeLists.txt
  * specify where to find node and nan include files
    *     include_directories(/usr/local/include ./node_modules/nan) 
  * Rename the executable because main is going to run tests
    *     add_executable(CppClassTest ${SOURCE_FILES})
  * Add the cpp unit test link library to the target:
    *     target_link_libraries(CppClassTest /usr/local/lib/libcppunit.a)

**Note**: when adding source files, the wrapper files should not be added to 
CMakeLists.txt, but the cpp unit test files should be added. 

For example: 
               
    set(SOURCE_FILES main.cpp \
        src/SampleObject.cpp \
        src/SampleObject.h \
        test/cpp/BoilerplateTestCase.cpp \
        test/cpp/BoilerplateTestCase.h \
        test/cpp/SampleObjectTestCase.cpp \
        test/cpp/SampleObjectTestCase.h)

Contains all the objects and their tests, but not the wrapper objects (src/SampleObjectWrap.cpp and src/SampleObjectWrap.h)


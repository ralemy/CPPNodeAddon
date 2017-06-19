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
* Created test/js directory
  * Created package.json file with chai as dev-dependency
  * npm install
  * created the boilerplate test file.
* Edited CMakeLists.txt
  * include_directories(/usr/local/include)
  * add_executable(CppClassTest ${SOURCE_FILES})
  * target_link_libraries(CppClassTest /usr/local/lib/libcppunit.a)
* Added bindings.gyp for node-gyp
* Created package.json in root directory and installed nan with npm.
* added NaN to the include directories of node-gyp 
* Added test/cpp and created unit tests for the C++ Object
* Added src directory and created the C++ object
* Added a wrapper class for sample object (note: not in the cmake targets, because it is only used by node-gyp)
  
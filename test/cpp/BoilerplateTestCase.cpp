//
// Created by Reza Alemy on 6/18/17.
//
#include <cassert>
#include "BoilerplateTestCase.h"

void BoilerplateTestCase::setUp(){
    message = "setup complete";
}
void BoilerplateTestCase::tearDown(){
    message = "";
}
void BoilerplateTestCase::testAssertion(){
    CPPUNIT_ASSERT(message == "setup complete");
}

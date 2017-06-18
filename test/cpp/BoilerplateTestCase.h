//
// Created by Reza Alemy on 6/18/17.
//

#ifndef OBJECTWRAP_NAN_BOILERPLATETESTCASE_H
#define OBJECTWRAP_NAN_BOILERPLATETESTCASE_H

#include <string>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

using namespace CppUnit;

class BoilerplateTestCase : public TestCase {
    CPPUNIT_TEST_SUITE(BoilerplateTestCase);
        CPPUNIT_TEST(testAssertion);
        CPPUNIT_TEST_SUITE_END();
public:
    void setUp();
    void tearDown();

protected:
    std::string message;
    void testAssertion();
};

CPPUNIT_TEST_SUITE_REGISTRATION(BoilerplateTestCase);


#endif //OBJECTWRAP_NAN_BOILERPLATETESTCASE_H

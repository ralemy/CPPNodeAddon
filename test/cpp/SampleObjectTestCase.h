//
// Created by Reza Alemy on 6/18/17.
//

#ifndef OBJECTWRAP_NAN_SAMPLEOBJECTTESTCASE_H
#define OBJECTWRAP_NAN_SAMPLEOBJECTTESTCASE_H

#include "../../src/SampleObject.h"
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>


using namespace CppUnit;

class SampleObjectTestCase : public TestCase {
CPPUNIT_TEST_SUITE(SampleObjectTestCase);
        CPPUNIT_TEST(testSampleMethod);
        CPPUNIT_TEST(testAddOperator);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp();

    void tearDown();

protected:
    SampleObject *referenceObject;

    void testSampleMethod();
    void testAddOperator();

};

CPPUNIT_TEST_SUITE_REGISTRATION(SampleObjectTestCase);

#endif //OBJECTWRAP_NAN_SAMPLEOBJECTTESTCASE_H

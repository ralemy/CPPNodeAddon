//
// Created by Reza Alemy on 6/18/17.
//

#include <cassert>
#include "SampleObjectTestCase.h"

void SampleObjectTestCase::setUp() {
    referenceObject = new SampleObject("test sample obj");
}

void SampleObjectTestCase::tearDown() {
    delete referenceObject;
}

void SampleObjectTestCase::testSampleMethod() {
    CPPUNIT_ASSERT_EQUAL(15,referenceObject->sampleMethod());
}

void SampleObjectTestCase::testAddOperator() {
    SampleObject *y = new SampleObject("second");
    SampleObject x = *referenceObject + *y;
    CPPUNIT_ASSERT_EQUAL(std::string("test sample obj second"),x.sampleState);

}

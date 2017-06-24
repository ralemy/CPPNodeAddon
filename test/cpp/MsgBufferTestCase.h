//
// Created by Reza Alemy on 6/23/17.
//

#ifndef OBJECTWRAP_NAN_MSGBUFFERTESTCASE_H
#define OBJECTWRAP_NAN_MSGBUFFERTESTCASE_H

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../../src/MsgBuffer.h"

using namespace CppUnit;

class SampleMsg {
public:
    std::string name;
    std::string data;
    SampleMsg(std::string name ="default name", std::string data="default data"): name(name), data(data) {};
};

class MsgBufferTestCase : public TestCase{
    CPPUNIT_TEST_SUITE(MsgBufferTestCase);
        CPPUNIT_TEST(testInstantiation);
            CPPUNIT_TEST(testWriteRead);
            CPPUNIT_TEST(testMulitplePush);
            CPPUNIT_TEST(testReadAll);
        CPPUNIT_TEST_SUITE_END();
public:
    void setUp();
    void tearDown();
private:
    MsgBuffer<SampleMsg> *reference = NULL;
    void testInstantiation();
    void testWriteRead();
    void testMulitplePush();
    void testReadAll();
};

CPPUNIT_TEST_SUITE_REGISTRATION(MsgBufferTestCase);

#endif //OBJECTWRAP_NAN_MSGBUFFERTESTCASE_H

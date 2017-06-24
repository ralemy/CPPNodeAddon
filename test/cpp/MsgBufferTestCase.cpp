//
// Created by Reza Alemy on 6/23/17.
//

#include <cassert>
#include "MsgBufferTestCase.h"

void MsgBufferTestCase::setUp() {
    reference = new MsgBuffer<SampleMsg>();
}

void MsgBufferTestCase::tearDown() {
    delete reference;
    reference = NULL;
}

void MsgBufferTestCase::testInstantiation() {
    CPPUNIT_ASSERT(reference != NULL);
}

void MsgBufferTestCase::testWriteRead() {
    reference->Write(* (new SampleMsg("name1","data1")));
    SampleMsg m = reference->Read();
    CPPUNIT_ASSERT_EQUAL(std::string("name1"), m.name);
    CPPUNIT_ASSERT_EQUAL(std::string("data1"), m.data);
}

void MsgBufferTestCase::testMulitplePush() {
    reference->Write(* (new SampleMsg("name1","data1")));
    reference->Write(* (new SampleMsg("name2","data2")));
    reference->Write(* (new SampleMsg("name3","data3")));
    SampleMsg m = reference->Read();
    m = reference->Read();
    CPPUNIT_ASSERT_EQUAL(std::string("name2"), m.name);
    m = reference->Read();
    CPPUNIT_ASSERT_EQUAL(std::string("name3"), m.name);
}

void MsgBufferTestCase::testReadAll() {
    reference->Write(* (new SampleMsg("name1","data1")));
    reference->Write(* (new SampleMsg("name2","data2")));
    reference->Write(* (new SampleMsg("name3","data3")));
    std::deque<SampleMsg> m;
    reference->ReadAll(m);
    CPPUNIT_ASSERT_EQUAL(3,(int)m.size());
    CPPUNIT_ASSERT_EQUAL(std::string("name1"), m.at(0).name);
    CPPUNIT_ASSERT_EQUAL(std::string("name2"), m.at(1).name);
    CPPUNIT_ASSERT_EQUAL(std::string("name3"), m.at(2).name);

}


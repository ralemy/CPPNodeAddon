//
// Created by Reza Alemy on 6/18/17.
//

#ifndef OBJECTWRAP_NAN_SAMPLEOBJECTWRAP_H
#define OBJECTWRAP_NAN_SAMPLEOBJECTWRAP_H

#include <node/node.h>
#include <nan.h>
#include "../src/SampleObject.h"

using namespace Nan;


class SampleObjectWrap : public ObjectWrap{
public:
    static NAN_MODULE_INIT(Init);

private:
    SampleObject *referenceObject;
    explicit SampleObjectWrap(std::string a = ""){
        referenceObject = new SampleObject(a);
    }
    virtual ~SampleObjectWrap(){
        delete referenceObject;
    }
    static NAN_METHOD(New);
    static NAN_METHOD(sampleMethod);

    static NAN_GETTER(GetSampleState);
    static NAN_SETTER(SetSampleState);

    static inline Nan::Persistent<v8::Function> & constructor() {
        static Nan::Persistent<v8::Function> my_constructor;
        return my_constructor;
    }

};


#endif //OBJECTWRAP_NAN_SAMPLEOBJECTWRAP_H

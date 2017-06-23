//
// Created by Reza Alemy on 6/18/17.
//
#include <string>
#include "SampleObjectWrap.h"

using namespace Nan;

NAN_MODULE_INIT(SampleObjectWrap::Init) {

    v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(SampleObjectWrap::New);

    tpl->SetClassName(Nan::New<v8::String>("SampleObject").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    SetPrototypeMethod(tpl, "sampleMethod", SampleObjectWrap::sampleMethod);

    v8::Local<v8::ObjectTemplate> itpl = tpl->InstanceTemplate();


    SetAccessor(itpl, Nan::New<v8::String>("sampleState").ToLocalChecked(),
                SampleObjectWrap::GetSampleState, SampleObjectWrap::SetSampleState);

    constructor().Reset(GetFunction(tpl).ToLocalChecked());

    Set(target, Nan::New("SampleObject").ToLocalChecked(), GetFunction(tpl).ToLocalChecked());
}

NAN_METHOD(SampleObjectWrap::New) {
    if(info.IsConstructCall()){
        std::string arg(info[0]->IsUndefined() ? "" : *v8::String::Utf8Value(info[0]->ToString()));
        (new SampleObjectWrap(arg))->Wrap(info.This());
        info.GetReturnValue().Set(info.This());
    }
    else{
        v8::Local<v8::Value> argv[1]={info[0]};
        v8::Local<v8::Function> cons = Nan::New(constructor());
        info.GetReturnValue().Set(cons->NewInstance(GetCurrentContext(),1,argv).ToLocalChecked());
    }
}

NAN_METHOD(SampleObjectWrap::sampleMethod) {
    SampleObjectWrap *w = ObjectWrap::Unwrap<SampleObjectWrap>(info.Holder());
    int result = w->referenceObject->sampleMethod();
    info.GetReturnValue().Set(Nan::New<v8::Number>(result));
}

NAN_GETTER(SampleObjectWrap::GetSampleState){
    SampleObjectWrap *w = ObjectWrap::Unwrap<SampleObjectWrap>(info.Holder());
    info.GetReturnValue().Set(Nan::New<v8::String>(w->referenceObject->sampleState.c_str()).ToLocalChecked());
}

NAN_SETTER(SampleObjectWrap::SetSampleState){
    SampleObjectWrap *w = ObjectWrap::Unwrap<SampleObjectWrap>(info.Holder());
    std::string arg(*v8::String::Utf8Value(value->ToString()));
    w->referenceObject->sampleState = arg;
}

void SampleObjectModule(v8::Local<v8::Object> exports) {
    SampleObjectWrap::Init(exports);
}

NODE_MODULE(SampleAddOn, SampleObjectModule)
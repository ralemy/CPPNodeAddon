//
// Created by Reza Alemy on 6/18/17.
//

#ifndef OBJECTWRAP_NAN_SAMPLEOBJECT_H
#define OBJECTWRAP_NAN_SAMPLEOBJECT_H


#include <string>

class SampleObject {
public:
    explicit SampleObject(std::string a = ""): sampleState(a){};
    virtual ~SampleObject(){};
    std::string sampleState;
    int sampleMethod();
    SampleObject operator+(SampleObject &y){
        return SampleObject(sampleState + " " + y.sampleState);
    }
};


#endif //OBJECTWRAP_NAN_SAMPLEOBJECT_H

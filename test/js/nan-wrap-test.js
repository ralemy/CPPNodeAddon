/**
 * Created by ralemy on 6/18/17.
 * Suite to test NAN Object wrap of a simple C++ class.
 */

const expect = require("chai").expect;

describe("NAN ObjectWrap test", ()=>{
    let addon, cls;
    it("should be able to require the addon", ()=>{
        addon = require("../../build/Release/SampleAddOn");
    });
    it("should be able to instantiate an object", ()=>{
        cls = new addon.SampleObject("first instance");
    });
    it("should allow for calling the constructor as a function", ()=>{
       let ocls = addon.SampleObject("second instance");
    });
    it("should allow for accessing the sampleState on the object", ()=>{
        expect(cls.sampleState).to.equal("first instance");
    });
    it("should allow for setting of the sampleState of the object", ()=>{
        cls.sampleState = "changed state";
        expect(cls.sampleState).to.equal("changed state");
        cls.sampleState = "first instance";
        expect(cls.sampleState).to.equal("first instance");
    });
    it("should allow for calling sampleMethod of the object",()=>{
        expect(cls.sampleMethod()).to.equal("first instance".length);
    });
});

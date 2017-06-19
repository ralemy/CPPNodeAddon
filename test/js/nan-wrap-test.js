/**
 * Created by ralemy on 6/18/17.
 * Suite to test NAN Object wrap of a simple C++ class.
 */

describe("NAN ObjectWrap test", ()=>{
    let addon, cls;
    it("should be able to require the addon", ()=>{
        addon = require("../../build/Release/SampleAddOn");
    });
    it("should be able to instantiate an object", ()=>{
        cls = new addon.SampleObject("my message");
    });
    it("should allow for calling the constructor as a function", ()=>{
       let ocls = addon.SampleObject("second instance");
    });
});

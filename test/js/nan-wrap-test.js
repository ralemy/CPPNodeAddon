/**
 * Created by ralemy on 6/18/17.
 * Suite to test NAN Object wrap of a simple C++ class.
 */

describe("NAN ObjectWrap test", ()=>{
    let addon;
    it("should be able to require the addon", ()=>{
        addon = require("../../build/Release/SampleAddOn");
    });
});

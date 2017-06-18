/**
 * Created by ralemy on 6/18/17.
 * boilerplate file showing that Mocha and chai are installed and working correctly on ES6
 */

const expect = require("chai").expect;

describe("Boilerplate Tests", () => {
    it("should have expect defined and assertions working", () => {
        expect(1).to.equal(1);
    });
});
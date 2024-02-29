var __spreadArray = (this && this.__spreadArray) || function (to, from, pack) {
    if (pack || arguments.length === 2) for (var i = 0, l = from.length, ar; i < l; i++) {
        if (ar || !(i in from)) {
            if (!ar) ar = Array.prototype.slice.call(from, 0, i);
            ar[i] = from[i];
        }
    }
    return to.concat(ar || Array.prototype.slice.call(from));
};
function plusOne(digits) {
    var length = digits.length;
    for (var idx = length - 1; idx >= 0; idx--) {
        digits[idx]++;
        if (digits[idx] < 10) {
            return digits;
        }
        digits[idx] = 0;
    }
    return __spreadArray([1], digits, true);
}

function lengthOfLastWord(s) {
    var end = s.length - 1;
    while (end >= 0 && s[end] === ' ') {
        end--;
    }
    if (end < 0) {
        return 0;
    }
    var newEnd = end;
    while (newEnd >= 0 && s[newEnd] !== ' ') {
        newEnd--;
    }
    return end - newEnd;
}
console.log(lengthOfLastWord('Hello World')); // 5
console.log(lengthOfLastWord(' ')); // 1
console.log(lengthOfLastWord('a')); // 1

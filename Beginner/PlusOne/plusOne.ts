function plusOne(digits: number[]): number[] {
    const length = digits.length;

    for (let idx = length - 1; idx >= 0; idx--) {
        digits[idx]++;

        if (digits[idx] < 10) {
            return digits;
        }

        digits[idx] = 0;
    }
    return [1, ...digits];
}
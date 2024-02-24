#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    // Constructs the 'next' array used in the KMP algorithm to optimize matching
    vector<int> buildNextArray(string pattern) {
        vector<int> next(pattern.length());
        next[0] = -1; // Initialization with -1 for the first character
        int index = 0; // Index in the pattern string
        int prefixIndex = -1; // Index of the longest prefix that is also a suffix
        int patternLength = pattern.length();
        while (index < patternLength) {
            // When there is a mismatch or it's the first iteration
            while (prefixIndex >= 0 && pattern[index] != pattern[prefixIndex])
                prefixIndex = next[prefixIndex];
            index++, prefixIndex++;
            // If we have not reached the end of the pattern
            if (index < patternLength) {
                // Record the length of the longest prefix which is also suffix
                if (pattern[index] == pattern[prefixIndex])
                    next[index] = next[prefixIndex];
                else
                    next[index] = prefixIndex;
            }
        }
        return next;
    }

public:
    // Function to find the first occurrence of `needle` in `haystack`
    int strStr(string haystack, string needle) {
        if (needle.empty()) // If the needle is empty, return 0 as per convention
            return 0;

        vector<int> nextArray = buildNextArray(needle);

        int haystackLength = haystack.length(); // Length of the haystack string
        int needleLength = needle.length(); // Length of the needle string
        int len = haystackLength - needleLength + 1; // Compute the limit of searching
        for (int i = 0; i < len; ++i) {
            int needleIndex = 0; // Index for the needle string
            int haystackIndex = i; // Starting index in the haystack string
            // Search while the characters match and we are within both strings
            while (needleIndex < needleLength && haystackIndex < haystackLength) {
                if (haystack[haystackIndex] != needle[needleIndex]) {
                    if (nextArray[needleIndex] >= 0) {
                        needleIndex = nextArray[needleIndex];
                        continue; // Use the next array to skip some comparisons
                    } else
                        break; // Mismatch without a valid sub-prefix match
                }
                ++haystackIndex, ++needleIndex;
            }
            // When the whole needle string has been traversed, return the starting index
            if (needleIndex == needleLength)
                return haystackIndex - needleIndex;
        }

        return -1; // If the needle has not been found, return -1
    }
};
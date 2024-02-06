// solving beginner level palindrom leetcode problem
#include <iostream>
using namespace std;


bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    long reversed = 0;
    int y = x; 

    while (y > 0) {
        reversed = reversed * 10 + y % 10;
        y /= 10;
    }

    return reversed == x;
}

int main()
{    
    int n;
    cout << "Enter a positive number: ";
    cin >> n;
    
    if (isPalindrome(n)) {
        cout << "The number is a palindrome." << endl;
    } else {
        cout << "The number is not a palindrome." << endl;
    }
}
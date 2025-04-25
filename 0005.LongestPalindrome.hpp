#include "codeKatas.h"

using namespace std;

// Given a string s, return the longest palindromic substring in s.

// TODO: fix me, time out on very long inputs that are palindromes

class LongestPalindrome {
public:
	string Solution(string s) {
        size_t front = 0, maxfront = 0, maxlen = 0;
        while (front < s.length()) {
            int len = 1;
            while (front + len <= s.length()) {
                if (isPalindrome(s.substr(front, len))) {
                    if (len > maxlen) {
                        maxlen = len;
                        maxfront = front;
                    }
                }
                len++;
            }
            front++;
        }

        return s.substr(maxfront, maxlen);
    }

    bool isPalindrome(string s) {
        size_t front = 0, back = s.length() - 1;
        while (front < back) {
            if (s[front] != s[back]) {
                return false;
            }
            front++;
            back--;
        }
        return true;
    }

    void Test(ostream& out, string s, string expected) {
        out << "s = " << s << " Expectation: " << expected;
        auto actual = Solution(s);
        out << " Actual: " << actual << " *** " << ((expected == actual) ? "Pass" : "Fail") << " ***" << endl;
    }

    LongestPalindrome(ostream& out) {
        Test(out, "babad", "bab");
        Test(out, "cbbd", "bb");
        Test(out, "a", "a");
        Test(out, "bb", "bb");
    }

};
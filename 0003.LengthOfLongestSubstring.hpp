#include "codeKatas.h"

using namespace std;

// Given a string s, find the length of the longest substring without duplicate characters.

class LengthOfLongestSubstring {
public:
	int Solution(string s) {
        string longestSub;
        size_t i = 0, j = 0, max = 0;
        while (j < s.length()) {
            if (longestSub.contains(s[j]) == false) {
                longestSub.push_back(s[j++]);
            }
            else {
                longestSub.erase(0, 1);
                ++i;
            }
            if (longestSub.length() > max) {
                max = longestSub.length();
            }
        }
        return static_cast<int>(max);
    }

	void Test(ostream& out, string s, int expected) {
        out << "s = " << s << " Expectation: " << expected;
        auto actual = Solution(s);
        out << " Actual: " << actual << " *** " << ((expected == actual) ? "Pass" : "Fail") << " ***" << endl;
    }

	LengthOfLongestSubstring(ostream& out) {
		Test(out, "abcabcbb", 3);
		Test(out, "bbbbb", 1);
		Test(out, "pwwkew", 3);
	}
};
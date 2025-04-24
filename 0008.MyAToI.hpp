#include "codeKatas.h"

using namespace std;

// Implement the myAtoi(string s) function, which converts a string to a 32 - bit signed integer.
// The algorithm for myAtoi(string s) is as follows :
//  Whitespace: Ignore any leading whitespace(" ").
//  Signedness : Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
//  Conversion : Read the integer by skipping leading zeros until a non - digit character is encountered or the end of the string is reached.If no digits were read, then the result is 0.
//  Rounding : If the integer is out of the 32 - bit signed integer range[-231, 231 - 1], then round the integer to remain in the range.Specifically, integers less than - 231 should be rounded to - 231, and integers greater than 231 - 1 should be rounded to 231 - 1.
//  Return the integer as the final result.

class MyAToI {
public:
	int Solution(string s) {
		size_t cursor = 0;
		while (isspace(s[cursor])) {
			cursor++;
		}
		int sign = 1;
		if (s[cursor] == '-') {
			sign = -1;
			cursor++;
		}
		else if (s[cursor] == '+') {
			cursor++;
		}

		long long ret = 0;
		while (isdigit(s[cursor])) {
			ret = 10L * ret + s[cursor] - '0';
			if (sign == -1) {
				if ((-1L * ret) <= numeric_limits<int>::min()) {
					return numeric_limits<int>::min();
				}
			}
			else {
				if (ret >= numeric_limits<int>::max()) {
					return numeric_limits<int>::max();
				}
			}
			cursor++;
		}
		return static_cast<int>(ret) * sign;
	}

	void Test(ostream& out, string s, int expected) {
		out << "s = " << s << " Expectation: " << expected;
		auto actual = Solution(s);
		out << " Actual: " << actual << " *** " << ((expected == actual) ? "Pass" : "Fail") << " ***" << endl;
	}

	MyAToI(ostream& out) {
		Test(out, "42", 42);
		Test(out, "  -042", -42);
		Test(out, "1337c0d3", 1337);
		Test(out, "0-1", 0);
		Test(out, "words and 987", 0);
		Test(out, "2147483646", 2147483646);
		Test(out, "2147483648", 2147483647);
		Test(out, "21474836460", 2147483647);
		Test(out, "-2147483647", -2147483647);
		Test(out, "-91283472332", -2147483648);
	}
};
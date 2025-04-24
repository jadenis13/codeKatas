#include "codeKatas.h"

using namespace std;

// Given a signed 32 - bit integer x, return x with its digits reversed.If reversing x causes the value to go outside the signed 32 - bit integer range[-231, 231 - 1], then return 0.
// Assume the environment does not allow you to store 64 - bit integers(signed or unsigned).

class Reverse {
public:
    int Solution(int x) {
        int reversed = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            if (reversed > numeric_limits<int>::max() / 10 || reversed < numeric_limits<int>::min() / 10) {
                return 0;
            }
            reversed = reversed * 10 + digit;
        }
        return reversed;
    }

    void Test(int x, int expected) {
        cout << "x = " << x << " Expectation: " << expected;
        auto actual = Solution(x);
        cout << " Actual: " << actual << " *** " << ((expected == actual) ? "Pass" : "Fail") << " ***" << endl;
    }

    Reverse() {
        Test(123, 321);
        Test(-123, -321);
        Test(120, 21);
    }

};
#include "codeKatas.h"

using namespace std;

// Given an integer x, return true if x is a palindrome, and false otherwise.

class IsPalindromeNumber {
public:
	bool Solution(int x) {
        if (x < 0) {
            return false;
        }
        if (x == 0) {
            return true;
        }
        size_t digitCount = 0;
        int test = x;
        while (test > 0) {
            digitCount++;
            test /= 10;
        }

        long long highPlace = static_cast<long long>(pow(10, digitCount - 1));
        long long lowPlace = 1;
        while (lowPlace < highPlace) {
            long long isolatedHigh = (x % (highPlace * 10)) / highPlace;
            long long isolatedLow = (x % (lowPlace * 10)) / lowPlace;
            if (isolatedHigh != isolatedLow) {
                return false;
            }
            highPlace /= 10;
            lowPlace *= 10;
        }
        return true;
    }

	void Test(int x, bool expected) {
		cout << "x = " << x << " Expectation: " << expected;
		auto actual = Solution(x);
		cout << " Actual: " << actual << " *** " << ((expected == actual) ? "Pass" : "Fail") << " ***" << endl;
	}

	IsPalindromeNumber() {
		Test(121, true);
        Test(-121, false);
        Test(10, false);
        Test(0, true);
        Test(1221, true);
        Test(2113113112, true);
    }
};
#include "codeKatas.h"

using namespace std;

// Given an integer, convert it to a Roman numeral.

class IntegerToRoman {
public:
    string Solution(int x) {
        const vector<pair<int, string>> valueToSymbol = {
             { 1000, "M" }, { 900, "CM" },
             { 500, "D" }, { 400, "CD" },
             { 100, "C" }, { 90, "XC" },
             { 50, "L" }, { 40, "XL" },
             { 10, "X" }, { 9, "IX" },
             { 5, "V" }, { 4, "IV" },
             { 1, "I" } 
        };
        string ret;
        while (x > 0) {
            for (const auto& [value, symbol] : valueToSymbol) {
                int divisor = x / value;
                x -= divisor * value;
                while (divisor > 0) {
                    ret.append(symbol);
                    --divisor;
                }
            }
        }
        return ret;
    }

    void Test(ostream& out, int x, string expected) {
        out << "x = " << x << " Expectation: " << expected;
        auto actual = Solution(x);
        out << " Actual: " << actual << " *** " << ((expected == actual) ? "Pass" : "Fail") << " ***" << endl;
    }

    IntegerToRoman(ostream& out) {
        Test(out, 3749, "MMMDCCXLIX");
        Test(out, 58, "LVIII");
        Test(out, 1994, "MCMXCIV");
    }
};
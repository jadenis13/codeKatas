#include "codeKatas.h"

using namespace std;

// There are n types of units indexed from 0 to n - 1. You are given a 2D integer array conversions of length n - 1, where conversions[i] = [sourceUniti, targetUniti, conversionFactori].This indicates that a single unit of type sourceUniti is equivalent to conversionFactori units of type targetUniti.
// Return an array baseUnitConversion of length n, where baseUnitConversion[i] is the number of units of type i equivalent to a single unit of type 0. Since the answer may be large, return each baseUnitConversion[i] modulo 109 + 7.
// Example 1:
// Input: conversions = [[0, 1, 2], [1, 2, 3]]
// Output : [1, 2, 6]

// Explanation :
//  Convert a single unit of type 0 into 2 units of type 1 using conversions[0].
//  Convert a single unit of type 0 into 6 units of type 2 using conversions[0], then conversions[1].

// Input : conversions = [[0, 1, 2], [0, 2, 3], [1, 3, 4], [1, 4, 5], [2, 5, 2], [4, 6, 3], [5, 7, 4]]
// Output : [1, 2, 3, 8, 10, 6, 30, 24]

class BaseUnitConversions {
public:
    vector<int> Solution(vector<vector<int>>& conversions) {
        const int SOURCE = 0;
        const int TARGET = 1;
        const int FACTOR = 2;

        vector<int> result(conversions.size() + 1);
        result[0] = 1;
        for (int i = 1; i < conversions.size() + 1; ++i) {
            long long local = static_cast<long long>(result[conversions[i - 1][SOURCE]]) * conversions[i - 1][FACTOR];
            result[conversions[i - 1][TARGET]] = static_cast<int>(local % 1000000007);
        }

        return result;
    }

    void Test(ostream& out, vector<vector<int>> conversions, vector<int> expected) {
        for (auto& vs : conversions) {
            out << "vs = " << vs;
        }
        out << " Expectation: " << expected;
        auto actual = Solution(conversions);
        out << " Actual: " << actual << " *** " << ((expected == actual) ? "Pass" : "Fail") << " ***" << endl;
    }

    BaseUnitConversions(ostream& out) {
        Test(out, { {0, 1, 2}, {1, 2, 3} }, { 1, 2, 6 });
        Test(out, { {0, 1, 2}, {0, 2, 3}, {1, 3, 4}, {1, 4, 5}, {2, 5, 2}, {4, 6, 3}, {5, 7, 4} }, { 1, 2, 3, 8, 10, 6, 30, 24 });
    }


};
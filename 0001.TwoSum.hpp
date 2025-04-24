#include "codeKatas.h"

using namespace std;

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

class TwoSum {
public:
	vector<int> Solution(vector<int>& nums, int target) {
        unordered_map<int, int> numsSeen;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (numsSeen.count(complement) > 0) {
                return { numsSeen[complement], i };
            }
            numsSeen[nums[i]] = i;
        }
        return {};
	}

    void Test(ostream& out, vector<int> nums, int target, vector<int> expected) {
        out << "nums = " << nums << " target = " << target << ". Expectation: " << expected;
        auto actual = Solution(nums, target);
        out << " Actual: " << actual << " *** " << ((expected == actual) ? "Pass" : "Fail") << " ***" << endl;
    }

    TwoSum(ostream& out) {
        Test(out, { 2, 7, 11, 15 }, 9, { 0, 1 });
        Test(out, { 3, 2, 4 }, 6, { 1, 2 });
        Test(out, { 3, 3 }, 6, { 0, 1 });
    }

};
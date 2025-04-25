#include "codeKatas.h"

using namespace std;

// You are given a 0 - indexed integer array nums, an integer modulo, and an integer k.
// Your task is to find the count of subarrays that are interesting.
// A subarray nums[l..r] is interesting if the following condition holds :
// Let cnt be the number of indices i in the range[l, r] such that nums[i] % modulo == k.Then, cnt% modulo == k.
// Return an integer denoting the count of interesting subarrays.
// Note : A subarray is a contiguous non - empty sequence of elements within an array.

class CountInterestingSubarrays {
public:
    long long Solution(vector<int>& nums, int modulo, int k) {
        long long result = 0;

        unordered_map<int, long long> count;
        count[0] = 1;

        int prefix = 0;
        for (int num : nums) {
            if (num % modulo == k) {
                prefix++;
            }
            
            result += count[(prefix - k) % modulo];
            count[prefix % modulo]++;
        }

        return result;
    }

    void Test(ostream& out, vector<int> nums, int modulo, int k, long long expected) {
        out << "nums = " << nums << " modulo = " << modulo << " k = " << k << " Expectation: " << expected;
        auto actual = Solution(nums, modulo, k);
        out << " Actual: " << actual << " *** " << ((expected == actual) ? "Pass" : "Fail") << " ***" << endl;
    }

    CountInterestingSubarrays(ostream& out) {
        Test(out, { 3,2,4 }, 2, 1, 3);
        Test(out, { 3,1,9,6 }, 3, 0, 2);
    }
};

#include "codeKatas.h"

using namespace std;

// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log(m + n)).

class FindMedianSortedArrays {
public:
	double Solution(vector<int>& nums1, vector<int>& nums2) {
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        vector<int> combined;
        while (combined.size() < (nums1.size() + nums2.size())) {
            if (it1 != nums1.end() && it2 != nums2.end()) {
                if (*it1 < *it2) {
                    combined.push_back(*it1);
                    ++it1;
                }
                else {
                    combined.push_back(*it2);
                    ++it2;
                }
            }
            else if (it1 != nums1.end()) {
                combined.push_back(*it1);
                ++it1;
            }
            else if (it2 != nums2.end()) {
                combined.push_back(*it2);
                ++it2;
            }
        }

        float median = static_cast<float>(combined[combined.size() / 2]);
        if (combined.size() % 2 != 1) {
            median += combined[combined.size() / 2 - 1];
            median /= 2.0f;
        }
        return median;
    }

    void Test(ostream& out, vector<int> nums1, vector<int> nums2, double expected) {
        out << "nums1 = " << nums1 << " nums2 = " << nums2 << " Expectation: " << expected;
        auto actual = Solution(nums1, nums2);
        out << " Actual: " << actual << " *** " << ((expected == actual) ? "Pass" : "Fail") << " ***" << endl;
    }

    FindMedianSortedArrays(ostream& out) {
        Test(out, { 1, 3 }, { 2 }, 2.0000);
        Test(out, { 1, 2 }, { 3, 4 }, 2.5000);
    }
};
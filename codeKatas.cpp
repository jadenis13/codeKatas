#include "codeKatas.h"
#include "0001.TwoSum.hpp"
#include "0002.AddTwoNumbers.hpp"
#include "0003.LengthOfLongestSubstring.hpp"
#include "0004.FindMedianSortedArrays.hpp"
#include "0005.LongestPalindrome.hpp"
#include "0007.Reverse.hpp"
#include "0008.MyAToI.hpp"
#include "0009.IsPalindromeNumber.hpp"

using namespace std;

ostream& operator<<(ostream& out, const vector<int>& v) {
	if (!v.empty()) {
		out << '['; ranges::copy(v, ostream_iterator<int>(out, ", ")); out << "\b\b]"; // overwrite trailing comma separator
	}
	return out;
}

int main() {
	auto twoSum = new TwoSum();
	auto addTwoNumbers = new AddTwoNumbers();
	auto lengthOfLongestSubstring = new LengthOfLongestSubstring();
	auto findMedianOfSortedArrays = new FindMedianSortedArrays();
	auto longestPalindrome = new LongestPalindrome();
	auto reverse = new Reverse();
	auto myAToI = new MyAToI();
	auto isPalindromeNumber = new IsPalindromeNumber();
	return 0;
}

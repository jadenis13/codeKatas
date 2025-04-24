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
	ostringstream out;
	auto twoSum = new TwoSum(out);
	auto addTwoNumbers = new AddTwoNumbers(out);
	auto lengthOfLongestSubstring = new LengthOfLongestSubstring(out);
	auto findMedianOfSortedArrays = new FindMedianSortedArrays(out);
	auto longestPalindrome = new LongestPalindrome(out);
	auto reverse = new Reverse(out);
	auto myAToI = new MyAToI(out);
	auto isPalindromeNumber = new IsPalindromeNumber(out);

	if (out.str().contains("Fail")) {
		return -1;
	}
	return 0;
}

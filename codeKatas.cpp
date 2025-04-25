#include "codeKatas.h"
#include "0001.TwoSum.hpp"
#include "0002.AddTwoNumbers.hpp"
#include "0003.LengthOfLongestSubstring.hpp"
#include "0004.FindMedianSortedArrays.hpp"
#include "0005.LongestPalindrome.hpp"
#include "0007.Reverse.hpp"
#include "0008.MyAToI.hpp"
#include "0009.IsPalindromeNumber.hpp"
#include "0012.IntegerToRoman.hpp"
#include "2845.CountInterestingSubarrays.hpp"
#include "3522.CalculateScore.hpp"

using namespace std;

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
	auto integerToRoman = new IntegerToRoman(out);
	auto countInterestingSubarrays = new CountInterestingSubarrays(out);
	auto calculateScore = new CalculateScore(out);

	if (out.str().contains("Fail")) {
		cout << out.str();
		return -1;
	}
	return 0;
}

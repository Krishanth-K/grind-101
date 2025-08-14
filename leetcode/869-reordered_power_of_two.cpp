// tag

// diff: medium

// url: https://leetcode.com/problems/reordered-power-of-2

#include "utils/vec.hpp"
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_set>

using std::cout, std::endl, utils::vector, std::string;

bool isPowerOfTwo(int num)
{
	if (num < 0)
		return false;

	while (num > 1)
	{
		if (num % 2 != 0)
			return false;
		num /= 2;
	}
	return num == 1;
}

// checks if the scrambed digits are powers of two
bool checkScrambledDigits(vector<int> &digits, int index = 0)
{
	// base case
	if (index == digits.size())
	{
		// early exit
		if (digits[0] == 0)
			return false;

		// reconstruct number from the digits
		int num = 0;
		for (const int &n : digits)
			num = num * 10 + n;

		return isPowerOfTwo(num);
	}

	for (int i = index; i < digits.size(); i++)
	{
		std::swap(digits[index], digits[i]); // swap two numbers (scramble)

		if (checkScrambledDigits(digits, index + 1)) // try all combinations
			return true;                             // short-circuit

		std::swap(digits[i], digits[index]); // swap two numbers (scramble)
	}

	return false;
}

std::unordered_set<string> buildSet()
{
	std::unordered_set<string> set;
	for (int i = 1; i <= 1e9; i *= 2)
	{
		string num = std::to_string(i);
		std::sort(num.begin(), num.end());
		set.insert(num);
	}

	return set;
}

bool bestSoln(int num)
{
	std::unordered_set<string> set = buildSet();

	string numString = std::to_string(num);
	std::sort(numString.begin(), numString.end());

	return set.count(numString) > 0;
}

class Solution {
  public:
	bool reorderedPowerOf2(int n)
	{
		if (n == 1)
			return true;
		// return checkScrambledDigits(digits);
		return bestSoln(n);
	}
};

int main()
{
	Solution soln;
	return 0;
}

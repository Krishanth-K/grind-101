// tag
// tag recursion

// url: https://leetcode.com/problems/powx-n/description/

// diff: medium

#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>

using std::cout, std::endl, std::vector;

double pow(std::unordered_map<int, double> &memo, double x, long n)
{
	if (n <= 0)
		return 1;
	else if (n == 1)
		return x;

	if (memo.find(n) != memo.end())
		return memo[n];

	double result;

	if (n % 2 == 0)
	{
		result = pow(memo, x, n / 2);
		memo[n / 2] = result;
		return result * result;
	}

	else
		result = pow(memo, x, (n / 2) + 1) * pow(memo, x, (n / 2));

	memo[n] = result;

	// a^(m + n) = a^m * a^n;
	return result;
}

class Solution {
  public:
	double myPow(double x, int n)
	{
		std::unordered_map<int, double> memo;

		if (n < 0)
		{
			double result = pow(memo, x, -(long)n);
			return 1 / result;
		}

		double result = pow(memo, x, n);
		return result;
	}
};

int main()
{
	Solution soln;

	return 0;
}

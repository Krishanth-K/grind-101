// tag
// tag recursion
// tag dp

// diff: medium

// url:
// https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/description/

#include <cmath>
#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int getRoot(int n, int x)
	{
		int root = std::pow(n, 1.0 / x);

		while (std::pow(root + 1, x) <= n)
			root += 1;

		return root;
	}

	int numberOfWays(int n, int x)
	{
		const int MOD = 1e9 + 7;

		// using dp
		// dp[ints upto i][target sum]

		int maxNum = getRoot(n, x);

		// dp table of: maxNum rows, n columns
		vector<vector<long long>> dp(maxNum + 1,
		                             std::vector<long long>(n + 1, 0));

		// dp[i][0] = 1 always
		for (int i = 0; i <= maxNum; i++)
			dp[i][0] = 1;

		for (int i = 1; i <= maxNum; i++)
		{
			int power = std::pow(i, x);

			for (int sum = 0; sum <= n; sum++)
			{
				// dp[i][sum] = dp[i-1][sum-i^2] (take i) + dp[i-1][sum] (not
				// take i)

				int take = 0;
				if (sum - power >= 0)
					take = dp[i - 1][sum - power];

				dp[i][sum] = (take + dp[i - 1][sum]) % MOD;
			}
		}

		return dp[maxNum][n];
	}

	// TODO: finish this updated function

	// since we only use the previous row, we can use just a 1-d array
	int betterSoln(int n, int x)
	{

		const int MOD = 1e9 + 7;

		int maxNum = getRoot(n, x);

		// vector<long long> dp());

		// dp[i][0] = 1 always
		for (int i = 0; i <= maxNum; i++)
			dp[i][0] = 1;

		for (int i = 1; i <= maxNum; i++)
		{
			int power = std::pow(i, x);

			for (int sum = 0; sum <= n; sum++)
			{
				// dp[i][sum] = dp[i-1][sum-i^2] (take i) + dp[i-1][sum] (not
				// take i)

				int take = 0;
				if (sum - power >= 0)
					take = dp[i - 1][sum - power];

				dp[i][sum] = (take + dp[i - 1][sum]) % MOD;
			}
		}

		return dp[maxNum][n];
	}
};

int main()
{
	Solution soln;
	std::cout << soln.decompose(5, 2);
	return 0;
}

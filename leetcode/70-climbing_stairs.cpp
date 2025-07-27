// tag double recursion
// tag recursion
// tag dp
// tag memoization

#include <iostream>
#include <unordered_map>
#include <vector>

using std::cout, std::endl, std::vector;

int countPossibilities(int stepsTaken, int totalSteps,
                       std::unordered_map<int, int> &memo)
{
	// base case: equal steps
	if (stepsTaken == totalSteps)
		return 1;

	// base case: overshot
	if (stepsTaken > totalSteps)
		return 0;

	// store the total number of possibilities until steps : stepsTaken
	// and use this to avoid repeated calc
	if (!memo[stepsTaken])
		memo[stepsTaken] = 0;
	else
		return memo[stepsTaken];

	// recursive cases
	int poss = countPossibilities(stepsTaken + 1, totalSteps, memo) +
	           countPossibilities(stepsTaken + 2, totalSteps, memo);

	// assign the value if not already stored
	memo[stepsTaken] = poss;

	return poss;
}

class Solution {
  public:
	int climbStairs(int n)
	{
		std::unordered_map<int, int> memo;
		return countPossibilities(0, n, memo);
	}
};

int main()
{
	int n = 12;
	Solution soln;

	cout << soln.climbStairs(n);
}

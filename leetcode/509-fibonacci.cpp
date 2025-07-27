// tag double recursion
// tag recursion
// tag dp
// tag memoization

#include <iostream>
#include <unordered_map>
#include <vector>

using std::cout, std::endl, std::vector;

int fibo(int n, std::unordered_map<int, int> &memo)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	// if (memo.find(n) == memo.end())
	// 	memo[n] = 0;
	// else
	// 	return memo[n];
	//
	int fib = fibo(n - 1, memo) + fibo(n - 2, memo);

	memo[n] = fib;
	return fib;
}

class Solution {
  public:
	int fib(int n)
	{
		std::unordered_map<int, int> memo;
		return fibo(n, memo);
	}
};

int main()
{
	Solution soln;
	return 0;
}

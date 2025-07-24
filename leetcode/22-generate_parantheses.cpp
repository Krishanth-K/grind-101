// look at .py version for notes

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void backtrack(string current, int openCount, int closeCount, int n,
               vector<string> &result)
{
	// base case:
	if (current.size() == 2 * n)
	{
		result.push_back(current);
		return;
	}

	// recursive cases

	// add more (
	if (openCount < n)
		backtrack(current + "(", openCount + 1, closeCount, n, result);

	// add more )
	if (closeCount < openCount)
		backtrack(current + ")", openCount, closeCount + 1, n, result);
}

class Solution {
  public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> result;

		string current = "";
		current.reserve(2 * n);

		backtrack("", 0, 0, n, result);
		return result;
	}
};

int main()
{
	Solution soln;
	vector<string> result = soln.generateParenthesis(100);
	for (const auto &e : result)
	{
		cout << e << ", ";
	}
}

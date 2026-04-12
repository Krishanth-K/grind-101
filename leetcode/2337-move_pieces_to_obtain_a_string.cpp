#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	bool canChange(string start, string target)
	{

		int n = start.size();
		int i = 0, j = 0;

		while (i < n || j < n)
		{
			// skip underscores
			while (i < n && start[i] == '_')
				i++;
			while (j < n && target[j] == '_')
				j++;

			// if both reach end, we are good
			if (i == n && j == n)
				return true;

			// piece count mismatch
			if (i == n || j == n)
				return false;

			if (start[i] != target[j])
				return false;
			if (start[i] == 'L' && j > i)
				return false;
			if (start[i] == 'R' && j < i)
				return false;

			i++;
			j++;
		}

		return true;
	}
};

int main()
{
	Solution soln;
	string s = "_L";
	string t = "LR";

	bool res = soln.canChange(s, t);
	cout << res;
	return 0;
}

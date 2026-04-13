#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int minOperations(vector<string> &logs)
	{
		int depth = 0;

		for (int i = 0; i < logs.size(); i++)
		{
			if (logs[i] == "../" && depth > 0)
				depth--;
			else if (logs[i] == "./")
				continue;
			else if (logs[i] != "../")
				depth++;
		}

		return depth;
	}
};

int main()
{
	Solution soln;

	vector<string> a = {"./", "../", "./"};
	cout << soln.minOperations(a);
	return 0;
}

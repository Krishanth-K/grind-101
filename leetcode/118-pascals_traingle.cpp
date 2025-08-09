// tag

// url:
// https://leetcode.com/problems/pascals-triangle/description/?envType=daily-question&envId=2025-08-01

#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

class Solution {
  public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> result;

		vector<int> one{1};
		vector<int> two{1, 1};

		// edge cases
		result.push_back(one);
		if (numRows == 1)
			return result;

		result.push_back(two);
		if (numRows == 2)
			return result;

		// add from prev layer to find new layer
		for (int i = 1; i < numRows - 1; i++)
		{
			vector<int> prev = result[result.size() - 1];

			vector<int> temp{1};
			for (int j = 0; j < i; j++)
			{
				temp.push_back(prev[j] + prev[j + 1]);
			}
			temp.push_back(1);

			result.push_back(temp);
		}

		return result;
	}
};

int main()
{
	Solution soln;

	vector<vector<int>> result = soln.generate(5);

	for (const auto &element : result)
	{
		for (const auto &item : element)
			cout << item << ", ";

		cout << endl;
	}

	return 0;
}

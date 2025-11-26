// tag

// diff: medium

// url: https://leetcode.com/problems/merge-intervals/

#include <algorithm>
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	vector<vector<int>> merge(vector<vector<int>> &intervals)
	{
		std::sort(intervals.begin(), intervals.end(),
		          [](const auto &a, const auto &b) { return a[0] < b[0]; });

		vector<vector<int>> res;
		res.push_back(intervals[0]);

		for (int i = 1; i < intervals.size(); i++)
		{
			vector<int> &current = res.back();
			vector<int> &next = intervals[i];

			// b1 >= a2 -> overlap overlap
			if (current[1] >= next[0])
				current[1] = std::max(current[1], next[1]);

			// b1 < a2 -> no overlap
			else
				res.push_back(next);
		}

		return res;
	}
};

int main()
{
	Solution soln;
	return 0;
}

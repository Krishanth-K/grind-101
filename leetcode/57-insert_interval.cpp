// tag

// diff: medium

// url: https://leetcode.com/problems/insert-interval/

#include <algorithm>
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	vector<vector<int>> insert(vector<vector<int>> &intervals,
	                           vector<int> &newInterval)
	{
		vector<vector<int>> res;
		int i = 0;
		int n = intervals.size();

		// add all intervals that end before new interval starts
		while (i < n && intervals[i][1] < newInterval[0])
		{
			res.push_back(intervals[i]);
			i++;
		}

		// merge intervals with new interval
		while (i < n && intervals[i][0] <= newInterval[1])
		{
			newInterval[0] = std::min(intervals[i][0], newInterval[0]);
			newInterval[1] = std::max(intervals[i][1], newInterval[1]);
			i++;
		}

		// add merged interval
		res.push_back(newInterval);

		// add remaining intervals
		while (i < n)
		{
			res.push_back(intervals[i]);
			i++;
		}

		return res;
	}
};

int main()
{
	Solution soln;
	return 0;
}

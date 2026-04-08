// diff: medium

#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int removeDuplicates(vector<int> &nums)
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(NULL);

		int n = nums.size();
		if (n <= 2)
			return n;

		int write = 2;

		for (int fast = 2; fast < n; fast++)
		{
			if (nums[fast] != nums[write - 2])
			{
				nums[write] = nums[fast];
				write++;
			}
		}

		return write;
	}
};
;

int main()
{
	Solution soln;
	vector<int> a = {0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	cout << soln.removeDuplicates(a) << endl;
	;

	for (int x : a)
		std::cout << x << ' ';

	return 0;
}

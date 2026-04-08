// diff:

#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int removeDuplicates(vector<int> &nums)
	{

		int n = nums.size();
		int slow = 0, fast = 0;

		std::unordered_map<int, int> map;

		while (fast < n)
		{
			int current = nums[fast];

			// already visited
			if (map.find(current) != map.end())
				fast++;

			// not visited
			else
			{
				map[current] = 0;
				nums[slow] = nums[fast];
				fast++;
				slow++;
			}
		}

		return slow;
	}
};

int main()
{
	Solution soln;
	vector<int> a = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	cout << soln.removeDuplicates(a) << endl;
	;

	for (int x : a)
		std::cout << x << ' ';

	return 0;
}

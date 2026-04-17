#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int totalFruit(vector<int> &fruits)
	{
		int n = fruits.size();
		int slow = 0, fast = 0;
		int count = 0;

		if (n <= 2)
			return n;

		// vector<int> map(n, 0);

		// using a fixed-size array is faster than dynamic-size vector
		int map[100001] = {0};

		int distinct = 0;

		for (fast = 0; fast < n; fast++)
		{
			if (map[fruits[fast]] == 0)
				distinct++;

			map[fruits[fast]]++;

			if (distinct >= 3)
			// while (distinct >= 3 && slow <= fast)
			{
				map[fruits[slow]]--;

				if (map[fruits[slow]] == 0)
					distinct--;

				slow++;
			}

			count = std::max(count, fast - slow + 1);
		}

		return count;
	}
};

int main()
{
	Solution soln;
	vector<int> a = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
	cout << soln.totalFruit(a);
	return 0;
}

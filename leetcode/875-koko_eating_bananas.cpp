#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	bool feasible(int k, vector<int> &piles, int h)
	{
		long long res = 0;

		for (const auto &pile : piles)
		{
			res += (pile + k - 1) / k;

			if (res > h)
				return false;
		}

		return res <= h;
	}

	int minEatingSpeed(vector<int> &piles, int h)
	{
		int lo = 1;
		int hi = *std::max_element(piles.begin(), piles.end());

		while (lo < hi)
		{
			int mid = lo + (hi - lo) / 2;

			// could eat slower
			if (feasible(mid, piles, h))
				hi = mid;

			// should eat faster
			else
				lo = mid + 1;
		}

		return lo;
	}
};

int main()
{
	Solution soln;

	vector<int> a{3, 6, 7, 11};
	cout << soln.minEatingSpeed(a, 8);
	return 0;
}

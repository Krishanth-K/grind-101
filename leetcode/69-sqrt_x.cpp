#include <climits>
#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int mySqrt(int x)
	{
		// handle 0 and 1
		if (x < 2)
			return x;

		int ans = 0;
		int left = 1, right = x / 2;

		while (left <= right)
		{
			int mid = left + (right - left) / 2;

			if (mid <= x / mid)
			{
				ans = mid;
				left = mid + 1;
			}
			else
				right = mid - 1;
		}

		return ans;
	}
};

int main()
{
	Solution soln;
	return 0;
}

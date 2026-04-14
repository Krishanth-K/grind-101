#include <climits>
#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int reverse(int x)
	{
		if (x == INT_MIN)
			return 0;

		int result = 0;
		while (abs(x) > 0)
		{
			int rem = x % 10;

			// check 1: result * 10 <= INT_MAX  => result <= INT_MAX / 10;
			if (abs(result) > INT_MAX / 10)
				return 0;

			// check 2: result * 10 + rem <= INT_MAX =>
			// rem <= INT_MAX - ( result * 10 );
			if (abs(rem) > INT_MAX - abs(result * 10))
				return 0;

			result = result * 10 + rem;
			x /= 10;
		}

		// if (negative)
		// 	return -1 * result;

		return result;
	}
};

int main()
{
	Solution soln;
	return 0;
}

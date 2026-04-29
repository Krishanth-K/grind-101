#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
  public:
	int guessNumber(int n)
	{
		int left = 0, right = n;

		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			int response = guess(mid);

			if (response < 0)
				right = mid - 1;
			else if (response > 0)
				left = mid + 1;
			else
				return mid;
		}

		return -1;
	}
};

int main()
{
	Solution soln;
	return 0;
}

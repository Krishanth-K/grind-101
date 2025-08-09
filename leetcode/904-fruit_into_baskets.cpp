// tag
// tag sliding_window
// tag hash_table

// diff: medium

// url:
// https://leetcode.com/problems/fruit-into-baskets/?envType=daily-question&envId=2025-08-04

#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

// algorithm:
// 1. take an index: ptr start <- i
// 2. create a window of size 2 (so i should be from 0 to size - 2)
// 3. make the two baskets contain the two type of fruits
//  3.1 If the two fruits are of same type, keep one basket empty
//

class Solution {
  public:
	int totalFruit(vector<int> &fruits)
	{
		int n = fruits.size();

		if (n == 1)
			return 1;
		if (n == 2)
			return 2;

		int maxCount = 0;
		int fruitOne = 0;
		int fruitTwo = 0;

		while (fruitTwo < n)
		{
			// move fruitTwo so that it is different from fruitOne
			while (fruitTwo < n && fruits[fruitTwo] == fruits[fruitOne])
				fruitTwo++;

			// now fruitTwo points to the fruit that is different from first
			// fruit

			// if all fruits from fruitOne to end are the same
			if (fruitTwo >= n)
			{
				int currentCount = fruitTwo - fruitOne;
				maxCount = maxCount > currentCount ? maxCount : currentCount;
				break;
			}

			// temp fruit
			int tempFruit = fruitTwo;

			while ((fruits[tempFruit] == fruits[fruitOne] ||
			        fruits[tempFruit] == fruits[fruitTwo]) &&
			       tempFruit < n)
				tempFruit++;

			// now tempFruit points to the fruit that is diff from both the
			// first and second fruits

			// current count in basket
			int currentCount = tempFruit - fruitOne;

			maxCount = maxCount > currentCount ? maxCount : currentCount;

			// for the next iteration, make the second fruit as first and
			// continue
			fruitOne = fruitTwo;
			fruitTwo = tempFruit;
		}

		return maxCount;
	}
};

int main()
{
	Solution soln;

	vector<int> arr = {0, 1, 2, 2};
	cout << soln.totalFruit(arr);

	return 0;
}

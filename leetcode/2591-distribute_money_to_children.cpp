// tag
//

// diff: easy

// url: https://leetcode.com/problems/distribute-money-to-maximum-children/

#include "utils/vec.hpp"
#include <iostream>
using std::cout, std::endl, utils::vector, std::string;

class Solution
{
  public:
	int distMoney(int money, int children)
	{
		money -= children;
		if (money < 0)
			return -1;
		if (money / 7 == children && money % 7 == 0)
			return children;
		if (money / 7 == children - 1 && money % 7 == 3)
			return children - 2;
		return std::min(children - 1, money / 7);
	}
};

int main()
{
	Solution soln;
	return 0;
}

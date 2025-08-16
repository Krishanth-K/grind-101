// tag
// tag substring

// diff: easy

// url: https://leetcode.com/problems/largest-3-same-digit-number-in-string/

#include "utils/vec.hpp"
#include <iostream>
#include <string>
using std::cout, std::endl, utils::vector, std::string;

class Solution {
  public:
	string largestGoodInteger(string num)
	{
		int goodInd = -1;

		for (int i = 0; i < num.size() - 2; i++)
		{
			if (num[i] == num[i + 1] && num[i + 1] == num[i + 2])
			{
				// first time
				if (goodInd == -1)
					goodInd = i;

				else if (num[i] > num[goodInd])
					goodInd = i;
			}
		}

		cout << goodInd << endl;

		// if no good num,
		if (goodInd == -1)
			return "";

		// convert good num to string
		char goodDigit = num[goodInd];

		return {goodDigit, goodDigit, goodDigit};
	}
};

int main()
{
	Solution soln;
	cout << soln.largestGoodInteger("6777133339");
	return 0;
}

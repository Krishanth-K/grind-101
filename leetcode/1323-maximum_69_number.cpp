// tag

// diff: easy

// url: https://leetcode.com/problems/maximum-69-number/

#include "utils/vec.hpp"
#include <iostream>
#include <string>
using std::cout, std::endl, utils::vector;

class Solution {
  public:
	int maximum69Number(int num)
	{
		std::string number = std::to_string(num);

		for (int i = 0; i < number.size(); i++)
		{
			if (number[i] == '6')
			{
				number[i] = '9';
				break;
			}
		}

		return std::stoi(number);
	}
};

int main()
{
	Solution soln;
	cout << soln.maximum69Number(69);
	return 0;
}

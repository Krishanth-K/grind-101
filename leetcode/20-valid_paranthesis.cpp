// tag
// tag stack

// diff: easy

// url: https://leetcode.com/problems/valid-parentheses/

#include "utils/vec.hpp"
#include <iostream>
#include <stack>
#include <unordered_map>
using std::cout, std::endl, utils::vector, std::string;

class Solution {
  public:
	// push open brackets to the stack, when encountering a closing bracket, see
	// if its the last opened bracket, that is the top bracket on the stack
	bool isValid(string s)
	{
		std::unordered_map<char, char> pair = {
		    {')', '('}, {']', '['}, {'}', '{'}};

		std::stack<char> stack;

		for (const char &c : s)
		{
			if (c == '(' || c == '[' || c == '{')
				stack.push(c);

			else
			{
				if (stack.size() != 0 && pair[c] == stack.top())
					stack.pop();

				else
					return false;
			}
		}

		// the stack is not empty
		if (stack.size() != 0)
			return false;

		return true;
	}
};

int main()
{
	Solution soln;
	return 0;
}

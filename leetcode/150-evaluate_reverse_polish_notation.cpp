#include <iostream>
#include <stack>
#include <string>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int applyOp(int a, int b, char op)
	{
		switch (op)
		{
		case '+':
			return a + b;
			break;
		case '-':
			return a - b;
			break;
		case '*':
			return a * b;
			break;
		case '/':
			return a / b;
			break;
		default:
			return a;
		}
	}

	bool isOperator(string i)
	{
		return ((i == "+") || (i == "-") || (i == "*") || (i == "/"));
	}

	int evalRPN(vector<string> &tokens)
	{
		std::stack<int> operands{};

		for (const auto &tok : tokens)
		{
			if (isOperator(tok))
			{
				int b = operands.top();
				operands.pop();
				int a = operands.top();
				operands.pop();

				operands.push(applyOp(a, b, tok[0]));
			}
			else
				operands.push(std::stoi(tok));
		}
		return operands.top();
	}
};

int main()
{
	Solution soln;
	return 0;
}

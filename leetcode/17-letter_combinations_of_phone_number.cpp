// tag

// diff: med

// url:
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

#include "utils/vec.hpp"
#include <iostream>
#include <unordered_map>
using std::cout, std::endl, utils::vector, std::string;

class Solution {
  public:
	vector<string> letterCombinations(string digits)
	{
		if (digits.size() == 0)
			return vector<string>{};

		cout << digits.size();
		vector<string> out{""};

		for (int i = 0; i < digits.size(); i++)
		{

			out = getCartesianProd(out, map[digits[i]]);
			for (const auto &a : out)
				cout << a << ", ";
			cout << endl;
		}

		return out;
	}

	vector<string> getCartesianProd(vector<string> &a, vector<string> &b)
	{
		vector<string> out{};

		for (const auto &x : a)
		{
			for (const auto &y : b)
			{
				out.push_back({x + y});
			}
		}

		return out;
	}

  private:
	std::unordered_map<char, vector<string>> map = {
	    {'2', vector<string>{"a", "b", "c"}},
	    {'3', vector<string>{"d", "e", "f"}},
	    {'4', vector<string>{"g", "h", "i"}},
	    {'5', vector<string>{"j", "k", "l"}},
	    {'6', vector<string>{"m", "n", "o"}},
	    {'7', vector<string>{"p", "q", "r", "s"}},
	    {'8', vector<string>{"t", "u", "v"}},
	    {'9', vector<string>{"w", "x", "y", "z"}},
	};
};

int main()
{
	Solution soln;
	soln.letterCombinations("23");
	return 0;
}

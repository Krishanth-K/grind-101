#include <iostream>
#include <vector>

using std::string, std::vector;

class Solution {
  public:
	string makeFancyString(string s)
	{

		int n = s.size();
		string result = "";

		char currentChar = s[0];
		int repeatCount = 0;

		// leeetcode
		for (int i = 0; i < n - 2; i++)
		{
			if (currentChar == s[i] && repeatCount <= 2)
			{
			}
		}

		// append last two chars
		result[n - 2] = s[n - 2];
		result[n - 1] = s[n - 1];

		return result;
	}
};

int main()
{
	Solution soln;

	std::cout << soln.makeFancyString("leeeetcode");
}

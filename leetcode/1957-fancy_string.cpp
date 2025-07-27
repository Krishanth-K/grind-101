#include <iostream>
#include <vector>

using std::string, std::vector;

class Solution {
  public:
	string makeFancyString(string s)
	{
		string result;
		int n = s.length();

		if (n < 3)
			return s;

		for (int i = 0; i < n; i++)
		{
			if ((result.length() < 2) ||
			    !(s[i] == result[result.length() - 1] &&
			      s[i] == result[result.length() - 2]))
				result += s[i];
		}

		return result;
	}
};

int main()
{
	Solution soln;

	std::cout << soln.makeFancyString("leeeetcode");
}

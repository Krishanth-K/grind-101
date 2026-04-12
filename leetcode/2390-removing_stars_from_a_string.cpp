#include <algorithm>
#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	string removeStars(string s)
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(NULL);

		int slow = 0;
		int fast = 0;

		while (fast < s.size())
		{
			if (s[fast] == '*')
				slow--;
			else
			{
				s[slow] = s[fast];
				slow++;
			}

			fast++;
		}

		return s.substr(0, slow);
	}

	// string removeStars(string s)
	// {
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(NULL);
	// 	int n = s.size();
	// 	int curr = n - 1;
	// 	int count = 0;
	//
	// 	string res = "";
	//
	// 	while (curr >= 0)
	// 	{
	// 		if (curr >= 0 && s[curr] != '*')
	// 		{
	// 			res.push_back(s[curr]);
	// 			curr--;
	// 			continue;
	// 		}
	//
	// 		// skip and keep track of continuous *
	// 		while (curr >= 0 && s[curr] == '*')
	// 		{
	// 			count++;
	// 			curr--;
	// 		}
	// 		// skip next 'count' chars
	// 		while (count != 0)
	// 		{
	// 			if (s[curr] == '*')
	// 				count++;
	// 			else
	// 				count--;
	//
	// 			curr--;
	// 		}
	// 	}
	//
	// 	std::reverse(res.begin(), res.end());
	//
	// 	return res;
	// }
};

int main()
{
	Solution soln;
	return 0;
}

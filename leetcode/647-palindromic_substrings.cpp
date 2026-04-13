#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int countSubstrings(string s)
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(NULL);

		int n = s.size();
		int count = 0;

		for (int i = 0; i < n; i++)
		{
			// odd center case:
			int width = 0;
			while (i - width >= 0 && i + width < n)
			{
				if (s[i - width] == s[i + width])
					count++;
				else
					break;

				width++;
			}

			// even center case
			width = 0;
			while (i - width >= 0 && i + width + 1 < n)
			{
				if (s[i - width] == s[i + width + 1])
					count++;
				else
					break;

				width++;
			}
		}

		return count;
	}
};

int main()
{
	Solution soln;

	string s = "fdsklf";
	int res = soln.countSubstrings(s);
	cout << res;

	return 0;
}

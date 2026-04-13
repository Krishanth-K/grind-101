#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	string longestPalindrome(string s)
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(NULL);

		int n = s.size();
		int start = 0;
		int max = 0;

		for (int i = 0; i < n; i++)
		{
			// odd center case:
			int width = 0;
			int curr_size = -1;
			while (i - width >= 0 && i + width < n)
			{
				if (s[i - width] == s[i + width])
				{
					// replace if larger than current max
					curr_size += 2;

					if (curr_size > max)
					{
						max = curr_size;
						start = i - width;
					}
				}
				else
					break;

				width++;
			}

			// even center case
			width = 0;
			curr_size = 0;
			while (i - width >= 0 && i + width + 1 < n)
			{
				// replace if larger than current max
				if (s[i - width] == s[i + width + 1])
				{
					curr_size += 2;

					if (curr_size > max)
					{
						max = curr_size;
						start = i - width;
					}
				}
				else
					break;
				width++;
			}
		}

		return s.substr(start, max);
	}
};

int main()
{
	Solution soln;

	string s = "abbc";
	string res = soln.longestPalindrome(s);
	cout << res;

	return 0;
}

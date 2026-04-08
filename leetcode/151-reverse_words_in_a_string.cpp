// diff: medium

#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	string reverseWords(string s)
	{
		int n = s.size();
		string res = "";

		int fast = n - 1, slow = n - 1;

		while (true)
		{
			// move fast pointer until reaching the end of a word
			while (fast >= 0 && s[fast] == ' ')
				fast--;

			if (fast < 0)
				break;

			// find the start of the word
			slow = fast;
			while (slow >= 0 && s[slow] != ' ')
				slow--;

			// string word = s.substr(slow + 1, fast - slow);
			// copy chars manually
			res += " ";

			int temp = slow + 1;
			while (temp <= fast)
			{
				res.push_back(s[temp]);
				temp++;
			}

			// add the word to the result

			if (slow == 0)
				break;
			slow--;
			fast = slow;
		}

		return string(res.begin() + 1, res.end());
	}
};

int main()
{
	Solution soln;

	string str = "_the sky is blue";

	cout << soln.reverseWords(str);

	return 0;
}

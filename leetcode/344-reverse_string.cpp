// diff: easy

#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	void reverseString(vector<char> &s)
	{
		int n = s.size();
		int left = 0, right = n - 1;

		while (left < right)
		{
			char temp = s[left];
			s[left] = s[right];
			s[right] = temp;

			left++;
			right--;
		}
	}
};

int main()
{
	Solution soln;
	return 0;
}

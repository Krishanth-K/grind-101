#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

// This block speeds up the judge's input/output processing
static const int speedup = []() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

class Solution {
  public:
	// optimised solution
	int maximumLength(string s)
	{
		int n = s.size();
		int slow = 0;
		// 1. Initialize to 0!
		int freq[26][52] = {0};

		for (int fast = 0; fast < n; fast++)
		{
			if (s[fast] != s[slow])
				slow = fast;

			int currentSize = fast - slow + 1;

			// Mark this length and all shorter lengths as "seen"
			for (int len = 1; len <= currentSize; len++)
				freq[s[slow] - 'a'][len]++;
		}

		int maxSize = -1;
		for (int charIdx = 0; charIdx < 26; charIdx++)
		{
			// Start len at 1, go up to n
			for (int len = 1; len <= n; len++)
			{
				// 2. Check if frequency is >= 3
				if (freq[charIdx][len] >= 3)
				{
					// 3. The answer is the length (len), not the frequency
					maxSize = std::max(maxSize, len);
				}
			}
		}

		return maxSize;
	}

	// // own solution
	// int maximumLength(string s)
	// {
	// 	int n = s.size();
	// 	int fast = 0, slow = 0;
	// 	std::unordered_map<string, int> freq;
	// 	int maxSize = -1;
	//
	// 	for (fast = 0; fast < n; fast++)
	// 	{
	// 		if (s[fast] != s[slow])
	// 			slow = fast;
	//
	// 		// add all possible substrings
	// 		for (int i = slow; i <= fast; i++)
	// 		{
	// 			int currentSize = fast - i + 1;
	// 			string substr = s.substr(i, currentSize);
	//
	// 			freq[substr]++;
	// 			if (freq[substr] >= 3 && currentSize > maxSize)
	// 				maxSize = currentSize;
	// 		}
	// 	}
	//
	// 	return maxSize;
	// }
};

int main()
{
	Solution soln;
	string s = "abcdabcddddabcddddccccbbbbaaaa";
	cout << soln.maximumLength(s);

	return 0;
}

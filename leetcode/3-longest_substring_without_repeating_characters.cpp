#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

// expand forward
// if the new char is already present, contract from left side until the char is
// not in window, then continue expansion

class Solution {
  public:
	int lengthOfLongestSubstring(string s)
	{
		int left = 0, right = 0;
		int n = s.size();
		int size = 0, max_size = 0;

		vector<int> lastSeen(128, -1);

		for (int right = 0; right < n; right++)
		{
			char curr = s[right];

			// jump if char is already in window
			if (lastSeen[curr] >= left)
				left = lastSeen[curr] + 1;

			// update lastSeen
			lastSeen[curr] = right;

			max_size = std::max(max_size, right - left + 1);
		}

		return max_size;
	}

	// int lengthOfLongestSubstring(string s)
	// {
	// 	int left = 0, right = 0;
	// 	int n = s.size();
	// 	int size = 0, max_size = 0;
	//
	// 	std::unordered_map<char, bool> map;
	// 	map.reserve(n);
	//
	// 	while (right < n)
	// 	{
	// 		char curr = s[right];
	//
	// 		// if new char not in window
	// 		if (map.find(curr) == map.end() || map[curr] == false )
	// 			map[curr] = true;
	//
	// 		// if new char already in window
	// 		else if (map[curr])
	// 		{
	// 			// move left until after the char
	// 			while (s[left] != curr)
	// 			{
	// 				map[s[left]] = false;
	// 				left++;
	// 				size--;
	// 			}
	// 			left++;
	// 			size--;
	// 		}
	//
	// 		right++;
	// 		size++;
	//
	// 		if (size > max_size)
	// 			max_size = size;
	// 	}
	//
	// 	return max_size;
	// }
};

int main()
{
	Solution soln;
	string s = "abaab!bb";
	soln.lengthOfLongestSubstring(s);
	return 0;
}

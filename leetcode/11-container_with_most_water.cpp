// tag
// tag two pointer

// diff: medium

// url: https://leetcode.com/problems/container-with-most-water/description/

#include <algorithm>
#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int maxArea(vector<int> &height)
	{
		int left = 0;
		int right = height.size() - 1;
		int max_area = 0;

		while (left < right)
		{
			int h_left = height[left];
			int h_right = height[right];

			// Calculate area only when we have potentially better boundaries
			int current_h = std::min(h_left, h_right);
			max_area = std::max(max_area, current_h * (right - left));

			// Skip lines that are shorter than our current boundaries
			if (h_left <= h_right)
			{
				while (left < right && height[left] <= h_left)
					left++;
			}
			else
			{
				while (left < right && height[right] <= h_right)
					right--;
			}
		}

		return max_area;
	}

	// O(n2)
	// int maxArea(vector<int> &height)
	// {
	// 	int max_area = 0;
	// 	int max_left = height[0];
	//
	// 	for (int i = 0; i < height.size(); i++)
	// 	{
	// 		max_left = std::max(height[i], max_left);
	//
	// 		if (height[i] < max_left)
	// 			continue;
	//
	// 		for (int j = height.size() - 1; j > i; j--)
	// 		{
	// 			int current_area = std::min(height[i], height[j]) * (j - i);
	// 			// std::cout << current_area << std::endl;
	// 			max_area = std::max(max_area, current_area);
	// 		}
	// 	}
	//
	// 	return max_area;
	// }
};

int main()
{
	Solution soln;
	return 0;
}

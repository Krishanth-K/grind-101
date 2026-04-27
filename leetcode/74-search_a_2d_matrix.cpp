#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	bool searchMatrix(vector<vector<int>> &matrix, int target)
	{
		// virutal array method
		// consider it as an entire array
		// find mid, then calculate its row, col from the index

		int n = matrix.size();
		int m = matrix[0].size();

		int left = 0, right = m * n - 1;

		while (left <= right)
		{
			int mid = left + (right - left) / 2;

			// map 1D coord back to 2D coords
			int row = mid / m;
			int col = mid % m; // steps taken within that row
			int val = matrix[row][col];

			if (val == target)
				return true;
			else if (val < target)
				left = mid + 1;
			else
				right = mid - 1;
		}

		return false;

		// // OWN METHOD -> EASY TO UNDERSTAND
		// int m = matrix[0].size();
		// int n = matrix.size();
		//
		// // early exit
		// if (target < matrix[0][0] || target > matrix[n - 1][m - 1])
		// 	return false;
		//
		// // find the row first
		// int left = 0, right = n - 1;
		// while (left < right)
		// {
		// 	int mid = left + (right - left) / 2;
		//
		// 	// smaller than the entire row
		// 	if (target < matrix[mid][0])
		// 		right = mid - 1;
		//
		// 	// larger than the entire row
		// 	else if (target > matrix[mid][m - 1])
		// 		left = mid + 1;
		//
		// 	// within this row
		// 	else
		// 	{
		// 		left = mid;
		// 		break;
		// 	}
		// }
		//
		// vector<int> &row = matrix[left];
		// left = 0, right = m - 1;
		//
		// // find the element within the found row
		// while (left <= right)
		// {
		// 	int mid = left + (right - left) / 2;
		//
		// 	if (row[mid] == target)
		// 		return true;
		// 	else if (target > row[mid])
		// 		left = mid + 1;
		// 	else
		// 		right = mid - 1;
		// }
		//
		// return false;
	}
};

int main()
{
	Solution soln;
	vector<vector<int>> matrix = {{1, 3}};
	cout << soln.searchMatrix(matrix, 3);
	return 0;
}

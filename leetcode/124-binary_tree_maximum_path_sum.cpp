#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right)
	    : val(x), left(left), right(right)
	{
	}
};

class Solution {
  public:
	int maxSum = INT_MIN;

	int helper(TreeNode *root)
	{
		if (!root)
			return 0;

		int val = root->val;
		int left = helper(root->left);
		int right = helper(root->right);

		// find which possibility gives the max sum
		maxSum = std::max(
		    {maxSum, val, val + left, val + right, val + left + right});

		// return the max path sum of this node to its parent.
		// shouldnt include val+left+right, as this path can be connected above
		// the path is "closed" (but should be taken for maxSum calculation)
		return std::max({val, val + left, val + right});
	}
	int maxPathSum(TreeNode *root)
	{
		int temp = helper(root);
		return maxSum;
	}
};

int main()
{
	Solution soln;
	return 0;
}

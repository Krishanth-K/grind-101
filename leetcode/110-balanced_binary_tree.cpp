#include <algorithm>
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
	int getDepth(TreeNode *root)
	{
		if (!root)
			return 0;
		if (!root->left && !root->right)
			return 1;

		int leftHeight = getDepth(root->left);
		int rightHeight = getDepth(root->right);

		return 1 + std::max(leftHeight, rightHeight);
	}

	bool isBalanced(TreeNode *root)
	{
		if (!root)
			return true;
		;
		if (!root->left && !root->right)
			return true;

		int leftHeight = getDepth(root->left);
		int rightHeight = getDepth(root->right);

		return (std::abs(leftHeight - rightHeight) <= 1) &&
		       isBalanced(root->left) && isBalanced(root->right);
	}
};

int main()
{
	Solution soln;
	return 0;
}

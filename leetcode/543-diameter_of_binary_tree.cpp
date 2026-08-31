#include <algorithm>
#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
	int maxDia = 0;

	int getDepth(TreeNode *node)
	{
		if (!node)
			return 0;
		if (!(node->right) && !(node->left))
			return 1;

		int leftDepth = getDepth(node->left);
		int rightDepth = getDepth(node->right);

		return 1 + std::max(leftDepth, rightDepth);
	}

	int diameterOfBinaryTree(TreeNode *root)
	{
		int leftDia = getDepth(root->left);
		int rightDia = getDepth(root->right);

		maxDia = std::max(maxDia, leftDia + rightDia);

		return std::max()
	}
};

int main()
{
	Solution soln;
	return 0;
}

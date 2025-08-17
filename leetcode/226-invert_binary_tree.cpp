// tag
// tag recursion
// tag trees

// diff: easy

// url: https://leetcode.com/problems/invert-binary-tree/

#include "utils/vec.hpp"
#include <iostream>
using std::cout, std::endl, utils::vector, std::string;

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

void invert(TreeNode *root)
{
	if (root == nullptr)
		return;

	TreeNode *temp = root->left;
	root->left = root->right;
	root->right = temp;

	invert(root->left);
	invert(root->right);
}

class Solution {
  public:
	TreeNode *invertTree(TreeNode *root)
	{
		invert(root);
		return root;
	}
};

int main()
{
	Solution soln;
	return 0;
}

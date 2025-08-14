// tag
// tag trees

// diff: easy

// url: https://leetcode.com/problems/binary-tree-inorder-traversal/

#include "utils/vec.hpp"
#include <iostream>
using std::cout, std::endl, utils::vector;

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

void inOrder(TreeNode *root, vector<int> &out)
{
	if (!root)
		return;

	inOrder(root->left, out);
	out.push_back(root->val);
	inOrder(root->right, out);
}

class Solution {
  public:
	vector<int> inorderTraversal(TreeNode *root)
	{
		vector<int> out;
		inOrder(root, out);

		return out;
	}
};

int main()
{
	Solution soln;
	return 0;
}

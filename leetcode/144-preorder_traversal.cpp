// tag

// diff: easy

// url: https://leetcode.com/problems/binary-tree-preorder-traversal/

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

void preorder(TreeNode *root, vector<int> &out)
{
	if (root == nullptr)
		return;

	out.push_back(root->val);
	preorder(root->left, out);
	preorder(root->right, out);
}

class Solution {
  public:
	vector<int> preorderTraversal(TreeNode *root)
	{
		vector<int> out;
		preorder(root, out);

		return out;
	}
};

int main()
{
	Solution soln;
	return 0;
}

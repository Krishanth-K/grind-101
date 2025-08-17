// tag

// diff: easy

// url: https://leetcode.com/problems/binary-tree-postorder-traversal/

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

void postorder(TreeNode *root, vector<int> &out)
{
	if (root == nullptr)
		return;

	postorder(root->left, out);
	postorder(root->right, out);
	out.push_back(root->val);
}

class Solution {
  public:
	vector<int> postorderTraversal(TreeNode *root)
	{
		vector<int> out;
		postorder(root, out);

		return out;
	}
};

int main()
{
	Solution soln;
	return 0;
}

// tag
// tag binary search tree
// tag recursion

// diff: medium

// url: https://leetcode.com/problems/validate-binary-search-tree/

#include "utils/vec.hpp"
#include <climits>
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

// each node returns its max and min
// if leaf node, left_max == right_min == val
//
// if right_min < val: return false;
// or if left_max > val: return false;
// else, min = left.max, max = right.min

bool validate(TreeNode *root, long low, long high)
{
	if (!root)
		return true;

	if (low >= root->val || high <= root->val)
		return false;

	return validate(root->left, low, root->val) &&
	       validate(root->right, root->val, high);
}

void inOrder(TreeNode *root, vector<int> &out)
{
	if (!root)
		return;

	inOrder(root->left, out);
	out.push_back(root->val);
	inOrder(root->right, out);
}

// the inorder traversal of a BST is always ascending
bool bestSoln(TreeNode *root)
{
	vector<int> inorder;
	inOrder(root, inorder);

	for (int i = 0; i < inorder.size() - 1; i++)
	{
		if (inorder[i] >= inorder[i + 1])
			return false;
	}

	return true;
}

class Solution {
  public:
	bool isValidBST(TreeNode *root)
	{
		// return validate(root, LONG_MIN, LONG_MAX);
		return bestSoln(root);
	}
};

int main()
{
	Solution soln;
	return 0;
}

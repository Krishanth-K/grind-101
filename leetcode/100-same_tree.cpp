// tag
// tag recursion
// tag trees

// diff: easy

// url: https://leetcode.com/problems/same-tree/

#include "utils/vec.hpp"
#include <climits>
#include <iostream>
#include <string>

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

// returns the preOrder of the given tree, returns the output in the given
// vector
void preOrder(TreeNode *root, vector<std::string> &preorder)
{
	if (root == nullptr)
	{
		preorder.push_back("null");
		return;
	}

	std::string val = std::to_string(root->val);
	preorder.push_back(val);
	preOrder(root->left, preorder);
	preOrder(root->right, preorder);
}

// compare the preorders of both the trees
bool badSoln(TreeNode *p, TreeNode *q)
{
	vector<std::string> order1, order2;

	preOrder(p, order1);
	preOrder(q, order2);

	if (order1 == order2)
		return true;

	return false;
}

// ===========================================================

bool isSame(TreeNode *p, TreeNode *q)
{
	// if both are null, they are same
	if (!p && !q)
		return true;

	if (p && q && p->val == q->val)
		return isSame(p->left, q->left) && isSame(p->right, q->right);

	return false;
}

bool bestSoln(TreeNode *p, TreeNode *q) { return isSame(p, q); }

class Solution {
  public:
	bool isSameTree(TreeNode *p, TreeNode *q)
	{
		// my soln
		// badSoln(p, q);

		// best soln
		return bestSoln(p, q);
	}
};

int main()
{
	Solution soln;
	return 0;
}

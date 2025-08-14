// tag
// tag recursion
// tag trees

// diff: easy

// url: https://leetcode.com/problems/symmetric-tree/

#include "utils/vec.hpp"
#include <iostream>
#include <queue>
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

// recursive
bool isSymm(TreeNode *left, TreeNode *right)
{
	if (!left && !right)
		return true;
	if (!left || !right)
		return false;
	if (left->val != right->val)
		return false;

	cout << "left: " << left->val << ",   right: " << right->val << endl;

	return isSymm(left->left, right->right) && isSymm(left->right, right->left);
}

// iterative using BFS
bool isSymmBFS(TreeNode *left, TreeNode *right)
{
	std::queue<TreeNode *> q;
	q.push(left);
	q.push(right);

	while (!q.empty())
	{
		TreeNode *left = q.front();
		q.pop();
		TreeNode *right = q.front();
		q.pop();

		if (!left && !right)
			continue;
		if (!left || !right)
			return false;
		if (left->val != right->val)
			return false;

		// push mirrored children
		q.push(left->left);
		q.push(right->right);
		q.push(left->right);
		q.push(right->left);
	}

	return true;
}

bool mySoln(TreeNode *root) { return isSymmBFS(root, root); }

class Solution {
  public:
	bool isSymmetric(TreeNode *root) { return mySoln(root); }
};

int main()
{
	Solution soln;
	return 0;
}

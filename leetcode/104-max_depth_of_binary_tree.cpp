// tag
// tag trees
// tag recursion

// diff: easy

// url: https://leetcode.com/problems/minimum-depth-of-binary-tree/

#include "utils/vec.hpp"
#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <queue>
#include <stack>
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

int getDepthRec(TreeNode *root)
{
	if (!root)
		return 0;

	// Leaf node
	if (!root->left && !root->right)
		return 1;

	// If one child is null, ignore it and take the other child's depth
	if (!root->left)
		return 1 + getDepthRec(root->right);
	if (!root->right)
		return 1 + getDepthRec(root->left);

	// Both children exist → take the smaller depth
	return 1 + std::min(getDepthRec(root->left), getDepthRec(root->right));
}

int getDepthItr(TreeNode *root)
{
	if (!root)
		return 0;

	std::queue<std::pair<TreeNode *, int>> q; // node + current depth
	q.push({root, 1});

	while (!q.empty())
	{
		auto [node, depth] = q.front();
		q.pop();

		// If it's a leaf, this is the min depth
		if (!node->left && !node->right)
		{
			return depth;
		}

		if (node->left)
		{
			q.push({node->left, depth + 1});
		}
		if (node->right)
		{
			q.push({node->right, depth + 1});
		}
	}

	return 0; // never reached
}

class Solution {
  public:
	int minDepth(TreeNode *root) { return getDepthItr(root); }
};

int main()
{
	Solution soln;
	return 0;
}

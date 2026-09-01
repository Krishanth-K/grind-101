#include <algorithm>
#include <iostream>
#include <unordered_map>
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
	int maxDia = 0;
	std::unordered_map<TreeNode *, int> maxDepth{};

	int getDepth(TreeNode *node)
	{
		if (!node)
		{
			maxDepth[node] = 0;
			return 0;
		}
		if (!(node->right) && !(node->left))
		{
			maxDepth[node] = 1;
			return 1;
		}

		int leftDepth = getDepth(node->left);
		int rightDepth = getDepth(node->right);

		maxDia = std::max(maxDia, leftDepth + rightDepth);

		return 1 + std::max(leftDepth, rightDepth);
	}

	int diameterOfBinaryTree(TreeNode *root)
	{
		getDepth(root);
		return maxDia;
	}
};

int main()
{
	Solution soln;
	return 0;
}

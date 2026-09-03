#include <algorithm>
#include <climits>
#include <iostream>
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
	int dfs(TreeNode *node, int maxSoFar)
	{
		if (!node)
			return 0;

		int count = (node->val >= maxSoFar) ? 1 : 0;
		int nextMax = std::max(maxSoFar, node->val);

		return count + dfs(node->left, nextMax) + dfs(node->right, nextMax);
	}

	int goodNodes(TreeNode *root)
	{
		// Fast I/O
		std::ios_base::sync_with_stdio(false);
		std::cin.tie(NULL);

		if (!root)
			return 0;
		return dfs(root, root->val);
	}
};

int main()
{
	Solution soln;
	return 0;
}

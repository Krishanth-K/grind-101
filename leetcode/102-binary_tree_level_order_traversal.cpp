#include <iostream>
#include <queue>
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
	vector<vector<int>> levelOrder(TreeNode *root)
	{
		vector<vector<int>> result{};
		std::queue<TreeNode *> q{};

		if (!root)
			return result;

		// initialise the queue with the root
		q.push(root);

		while (!q.empty())
		{
			int size = q.size();

			// push children, while reading and appending current level nodes to
			// result
			vector<int> currentLevel(size);

			for (int i = 0; i < size; i++)
			{
				TreeNode *node = q.front();
				q.pop();

				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);

				// currentLevel.push_back(node->val);
				currentLevel[i] = node->val;
			}

			result.push_back(currentLevel);
		}

		return result;
	}
};

int main()
{
	Solution soln;
	return 0;
}

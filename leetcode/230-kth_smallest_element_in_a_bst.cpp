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
	void Inorder(TreeNode *root, vector<int> &result)
	{
		if (!root)
			return;

		Inorder(root->left, result);
		result.push_back(root->val);
		Inorder(root->right, result);
	}

	int kthSmallest(TreeNode *root, int k)
	{
		vector<int> inorder;
		Inorder(root, inorder);

		return inorder[k - 1];
	}
};

int main()
{
	Solution soln;
	return 0;
}

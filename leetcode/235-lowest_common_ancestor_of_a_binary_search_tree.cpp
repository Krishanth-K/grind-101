#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		// one node on either side
		if (((p->val < root->val) && (root->val < q->val)) ||
		    ((q->val < root->val) && (root->val < p->val)))
			return root;

		// root node is an ancestor as well as a descendant
		if ((p->val == root->val) || (root->val == q->val))
			return root;

		// both nodes on one side of the root
		if (p->val < root->val)
			return lowestCommonAncestor(root->left, p, q);
		else
			return lowestCommonAncestor(root->right, p, q);
	}
};

int main()
{
	Solution soln;
	return 0;
}

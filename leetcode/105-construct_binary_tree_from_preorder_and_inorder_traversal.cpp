#include <algorithm>
#include <iostream>
#include <iterator>
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

// the first node in preorder traversal is the root node
// the root node will be in the middle of inorder (approx)
// it seperates left and right

class Solution {
  public:
	// int binSearch(vector<int> &arr, int target)
	// {
	// 	int n = arr.size();
	// 	int lo = 0;
	// 	int hi = n - 1;
	//
	// 	while (lo <= hi)
	// 	{
	// 		int mid = lo + (hi - lo) / 2;
	//
	//            if (arr[mid] == target) return mid;
	//            if (a)
	// 	}
	// }

	TreeNode *helper(int preStart, int preEnd, vector<int> &preorder,
	                 int inStart, int inEnd, vector<int> &inorder)
	{
		if (preStart > preEnd || inStart > inEnd)
			return nullptr;

		int rootValue = preorder[preStart];
		TreeNode *root = new TreeNode(rootValue);

		auto midIt = std::find(inorder.begin(), inorder.end(), rootValue);
		if (midIt == inorder.end())
			return nullptr;

		int mid = midIt - inorder.begin();
		int leftSize = mid - inStart;

		//  root.left  = buildTree(preorder[1:1+left_size], inorder[:mid])
		// root.right = buildTree(preorder[1+left_size:],  inorder[mid+1:])

		TreeNode *left = helper(preStart + 1, preStart + leftSize, preorder,
		                        inStart, mid - 1, inorder);

		TreeNode *right = helper(preStart + leftSize + 1, preEnd, preorder,
		                         mid + 1, inEnd, inorder);

		root->left = left;
		root->right = right;

		return root;
	}

	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
	{
		int n = preorder.size();
		int m = inorder.size();
		return helper(0, n - 1, preorder, 0, m - 1, inorder);
	}
};

int main()
{
	Solution soln;
	return 0;
}

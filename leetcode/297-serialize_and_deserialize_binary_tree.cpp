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

// better solution would be to use a level order traversal, like leetcode
// instead of this bracket method

class Solution {
  public:
	string serHelper(TreeNode *root)
	{
		if (!root)
			return "#";

		string left = "(" + serHelper(root->left) + ")";
		string right = "(" + serHelper(root->right) + ")";

		return left + std::to_string(root->val) + right;
	}

	// Encodes a tree to a single string.
	string serialize(TreeNode *root) { return serHelper(root); }

	int getRootIndex(string &data, int lo, int hi)
	{
		// idea is to find the left tree within ( ) based on the no of
		// open/closed brackets

		int open = 0;
		int closed = 0;
		int idx = lo;

		do
		{
			if (data.at(idx) == '(')
				open++;
			else if (data.at(idx) == ')')
				closed++;

			idx++;
		}
		while (open > closed && idx <= hi);

		return idx;
	}

	TreeNode *deserHelper(string &data, int lo, int hi)
	{
		// a single node
		if (lo == hi)
		{
			char value = data.at(lo);
			if (value == '#')
				return nullptr;
			else
				return new TreeNode(value - '0');
		}

		// get start index of root
		int rootStartIndex = getRootIndex(data, lo, hi);

		// find the end index of root
		int rootEndIndex = rootStartIndex;
		while (data.at(rootEndIndex) != '(')
			rootEndIndex++;

		// finally rootStartIndex points to first digit of root, rootEndIndex
		// points to the first '(' after the root

		// the +1 and -2 are to strip the enclosing ( (..).(..) ) and to pass in
		// only the subtree data
		TreeNode *leftTree = deserHelper(data, lo + 1, rootStartIndex - 2);
		TreeNode *rightTree = deserHelper(data, rootEndIndex + 1, hi - 1);

		// int rootVal = data.at(rootStartIndex) - '0';
		int rootVal = std::stoi(
		    data.substr(rootStartIndex, rootEndIndex - rootStartIndex + 1));
		TreeNode *root = new TreeNode(rootVal);

		root->left = leftTree;
		root->right = rightTree;

		return root;
	}

	// Decodes your encoded data to tree.
	TreeNode *deserialize(string data)
	{
		return deserHelper(data, 0, data.length() - 1);
	}
};

int main()
{
	Solution soln;
	return 0;
}

#include <iostream>
#include <string>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
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

TreeNode *buildTree(vector<string> &nums)
{
	if (nums.empty() || nums[0] == "null")
		return nullptr;

	TreeNode *root = new TreeNode(stoi(nums[0]));

	vector<TreeNode *> nodes = {root};

	int i = 1;

	for (TreeNode *node : nodes)
	{
		if (i < nums.size() && nums[i] != "null")
		{
			node->left = new TreeNode(stoi(nums[i]));
			nodes.push_back(node->left);
		}
		i++;

		if (i < nums.size() && nums[i] != "null")
		{
			node->right = new TreeNode(stoi(nums[i]));
			nodes.push_back(node->right);
		}
		i++;
	}

	return root;
}

int main()
{
	Codec soln;

	vector<string> input = {
	    "41",   "37",   "44",   "24",   "39",   "42",   "48",   "1",    "35",
	    "38",   "40",   "null", "43",   "46",   "49",   "0",    "2",    "30",
	    "36",   "null", "null", "null", "null", "null", "null", "45",   "47",
	    "null", "null", "null", "null", "null", "4",    "29",   "32",   "null",
	    "null", "null", "null", "null", "3",    "9",    "26",   "null", "31",
	    "34",   "null", "null", "7",    "11",   "25",   "27",   "null", "null",
	    "33",   "null", "6",    "8",    "10",   "16",   "null", "null", "null",
	    "28",   "null", "null", "5",    "null", "null", "null", "null", "null",
	    "15",   "19",   "null", "null", "null", "null", "12",   "null", "18",
	    "20",   "null", "13",   "17",   "null", "null", "22",   "null", "14",
	    "null", "null", "21",   "23"};

	TreeNode *root = buildTree(input);

	// Tree -> String
	string serialized = soln.serialize(root);

	// String -> Tree
	TreeNode *deserialized = soln.deserialize(serialized);

	// Tree -> String again
	string reserialized = soln.serialize(deserialized);

	cout << "Serialized:    " << serialized << endl;
	cout << "Reserialized:  " << reserialized << endl;

	if (serialized == reserialized)
		cout << "\nPASS" << endl;
	else
		cout << "\nFAIL" << endl;

	return 0;
}

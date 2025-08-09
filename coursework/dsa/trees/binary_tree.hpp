#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <utils/vec.hpp>

class Node {

  public:
	int value;
	Node *right;
	Node *left;

	Node(int value, Node *right = nullptr, Node *left = nullptr)
	    : value(value), right(right), left(left) {};

	void AddLeftChild(int value) { left = new Node(value); }
	void AddLeftChild(Node *node) { left = node; }
	void AddRightChild(int value) { right = new Node(value); }
	void AddRightChild(Node *node) { right = node; }
};

class BinaryTree {
  public:
	Node *root;

	BinaryTree(Node *root) : root(root) {};
	BinaryTree() : root(nullptr) {};

	void static PrintInOrder(Node *root)
	{
		if (root == nullptr)
			return;
		PrintInOrder(root->left);
		std::cout << root->value << ", ";
		PrintInOrder(root->right);
	}

	void static PrintPreOrder(Node *root)
	{
		if (root == nullptr)
			return;

		std::cout << root->value << ", ";
		PrintInOrder(root->left);
		PrintInOrder(root->right);
	}

	void static PrintPostOrder(Node *root)
	{
		if (root == nullptr)
			return;
		PrintInOrder(root->left);
		PrintInOrder(root->right);
		std::cout << root->value << ", ";
	}

	// construct tree from InOrder and PreOrder traversals BinaryTree *
	static Node *ConstructTreeInPre(utils::vector<int> &inOrder,
	                                utils::vector<int> &preOrder)
	{
		if (inOrder.size() == 1)
			return new Node(inOrder[0]);
		if (inOrder.size() == 0)
			return nullptr;

		// the root is always the first elemnt in preOrder
		int pivotElement = preOrder[0];

		// create the root of the current subtree
		Node *root = new Node(pivotElement);

		// find the index of the element
		int pivotIndex = inOrder.find(pivotElement);

		utils::vector<int> leftHalf = inOrder.getSlice(0, pivotIndex);
		utils::vector<int> rightHalf =
		    inOrder.getSlice(pivotIndex + 1, inOrder.size());

		// the next pivotIndex elements -> left subtree. and remaining -> right
		// subtree
		utils::vector<int> leftPreOrder = preOrder.getSlice(1, 1 + pivotIndex);
		utils::vector<int> rightPreOrder = preOrder.getSlice(1 + pivotIndex);

		root->AddLeftChild(ConstructTreeInPre(leftHalf, leftPreOrder));
		root->AddRightChild(ConstructTreeInPre(rightHalf, rightPreOrder));

		return root;
	}

	void static PrintLeafNodes(BinaryTree &tree)
	{
		std::stack<Node *> stack;

		// initial value
		stack.push(tree.root);

		while (!stack.empty())
		{
			Node *top = stack.top();
			stack.pop();

			if (top->left != nullptr)
				stack.push(top->left);
			if (top->right != nullptr)
				stack.push(top->right);

			if (top->left == nullptr && top->right == nullptr)
				std::cout << top->value << ", ";
		}
	}

	int GetHeight()
	{
		int maxHeight = 0;

		// queue contains the current node and its height level
		std::queue<std::pair<Node *, int>> queue;

		// push the root to the queue
		queue.push(std::pair(this->root, 1));

		while (!queue.empty())
		{
			std::pair<Node *, int> pair = queue.front();
			Node *node = pair.first;
			int currentHeight = pair.second;

			queue.pop();

			if (node->right == nullptr && node->left == nullptr)
			{
				maxHeight = std::max(maxHeight, currentHeight);
				currentHeight = 0;
			}

			// add other nodes to the queue
			if (node->left != nullptr)
				queue.push(std::pair(node->left, currentHeight + 1));

			if (node->right != nullptr)
				queue.push(std::pair(node->right, currentHeight + 1));
		}

		return maxHeight;
	}
};

// #include <algorithm>
// #include <iostream>
// #include <queue>
// #include <stack>
// #include <utils/vec.hpp>
//
// class Node {
//   public:
// 	int value;
// 	Node *right;
// 	Node *left;
//
// 	Node(int value, Node *right = nullptr, Node *left = nullptr)
// 	    : value(value), right(right), left(left) {};
//
// 	void AddLeftChild(int value);
// 	void AddLeftChild(Node *node);
// 	void AddRightChild(int value);
// 	void AddRightChild(Node *node);
// };
//
// class BinaryTree {
//   public:
// 	Node *root;
//
// 	BinaryTree(Node *root) : root(root) {};
// 	BinaryTree() : root(nullptr) {};
//
// 	void static PrintInOrder(Node *root);
// 	void static PrintPreOrder(Node *root);
// 	void static PrintPostOrder(Node *root);
//
// 	// construct tree from InOrder and PreOrder traversals BinaryTree *
// 	static Node *ConstructTreeInPre(utils::vector<int> &inOrder,
// 	                                utils::vector<int> &preOrder);
//
// 	void static PrintLeafNodes(BinaryTree &tree);
// 	int GetHeight();
// };

#include "binary_tree.hpp"

using std::cout;
using std::endl;
using utils::vector;

int main()
{

	// Node *root = new Node(1);
	// root->AddLeftChild(2);              // b
	// root->left->AddLeftChild(4);        // d
	// root->left->left->AddLeftChild(8);  // h
	// root->left->left->AddRightChild(9); // i
	// root->left->AddRightChild(5);
	// root->AddRightChild(3);
	// root->right->AddLeftChild(6);
	// root->right->AddRightChild(7);

	// BinaryTree tree(root);

	// 	cout << endl << "In Order" << endl;
	// 	tree.PrintInOrder(root);
	// 	cout << endl << "Pre Order" << endl;
	// 	tree.PrintPreOrder(root);
	// 	cout << endl << "Post Order" << endl;
	// 	tree.PrintPostOrder(root);

	vector<int> inOrder = {6, 4, 7, 2, 5, 8, 1, 9, 3, 10};
	vector<int> preOrder = {1, 2, 4, 6, 7, 5, 8, 3, 9, 10};

	BinaryTree tree;

	Node *root = tree.ConstructTreeInPre(inOrder, preOrder);

	tree.root = root;
	tree.PrintInOrder(root);
	// cout << endl;
	// tree.PrintLeafNodes(tree);
	// cout << endl;
	// cout << tree.GetHeight();
}

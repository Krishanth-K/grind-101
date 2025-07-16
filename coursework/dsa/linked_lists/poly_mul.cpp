#include <iostream>

class Node {

  public:
	int coeff;
	int degree;
	Node *next;

  public:
	Node(int coeff, int degree)
	    : coeff(coeff), degree(degree), next(nullptr) {};

	bool addNode(int coeff, int degree)
	{
		next = new Node(coeff, degree);

		if (!next)
			return false;

		return true;
	}
};

class LinkedList {
  public:
	Node *head;

	LinkedList() : head(nullptr) {};

  public:
	bool addNode(int coeff, int degree)
	{
		if (head == nullptr)
		{
			head = new Node(coeff, degree);
			return true;
		}

		Node *temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = new Node(coeff, degree);

		return true;
	}
};

bool poly_mul(LinkedList &l1, LinkedList &l2, LinkedList &out)
{
	// fix one eqn
	// iterate through another eqn and multiply each term with every term of
	// first one multiply coeffs and create/insert the value into the
	// appropriate node in the output for the second iteration, degree will be 1
	// less than max degree repeat

	Node *a = l1.head;
	Node *b = l2.head;
}

int main() {}

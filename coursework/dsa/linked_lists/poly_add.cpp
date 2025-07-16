// You are given two linked lists representing a polynomial
// The goal is to add the two polynomials
//
//     Structure : Node -> (coeff, degree, link)

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

	LinkedList operator+(Node &node) {}
};

void printList(LinkedList &list)
{
	Node *head = list.head;
	while (head->next != nullptr)
	{
		std::cout << head->coeff << ", " << head->degree << "  |  ";
		head = head->next;
	}
	std::cout << head->coeff << ", " << head->degree << std::endl;
}

// add two polynomials listed as linked lists
bool poly_add(LinkedList &a, LinkedList &b, LinkedList &out)
{
	Node *head1 = a.head;
	Node *head2 = b.head;

	while (head1 != nullptr && head2 != nullptr)
	{
		// if one degree more than other, preserve the larger degree
		if (head1->degree > head2->degree)
		{
			out.addNode(head1->coeff, head1->degree);
			head1 = head1->next;
		}
		else if (head1->degree < head2->degree)
		{
			out.addNode(head2->coeff, head2->degree);
			head2 = head2->next;
		}

		// if equal degree, add them
		else
		{
			out.addNode(head1->coeff + head2->coeff, head1->degree);
			head1 = head1->next;
			head2 = head2->next;
		}
	}

	// add remaining nodes at the end
	while (head1 != nullptr)
	{
		out.addNode(head1->coeff, head1->degree);
		head1 = head1->next;
	}
	while (head2 != nullptr)
	{
		out.addNode(head2->coeff, head2->degree);
		head2 = head2->next;
	}

	return true;
}

int main()
{
	// Node l1(2, 8);
	LinkedList l1;
	l1.addNode(2, 3);
	l1.addNode(3, 1);
	l1.addNode(8, 0);

	LinkedList l2;
	l2.addNode(4, 3);
	l2.addNode(8, 2);
	l2.addNode(15, 0);

	LinkedList out;
	poly_add(l1, l2, out);

	printList(l1);
	printList(l2);
	printList(out);
}

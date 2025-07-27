#include <iostream>

class Node {

  public:
	int value;
	Node *next;
	Node *prev;

  public:
	Node(int value) : value(value), next(nullptr), prev(nullptr) {};
};

class DoubleLinkedList {
  public:
	Node *head;
	DoubleLinkedList() : head(nullptr) {};

	void addNode(int value)
	{
		if (head == nullptr)
		{
			head = new Node(value);
			return;
		}

		Node *temp = head;
		while (temp->next != nullptr)
			temp = temp->next;

		temp->next = new Node(value);
		temp->next->prev = temp;
	}

	void printList()
	{
		Node *temp = head;
		while (temp != nullptr)
		{
			std::cout << temp->value << ", ";
			temp = temp->next;
		}

		std::cout << std::endl;
	};
};

int main()
{
	DoubleLinkedList ll;
	ll.addNode(1);
	ll.addNode(2);

	ll.printList();
}

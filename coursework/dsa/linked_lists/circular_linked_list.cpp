#include <iostream>

class Node {

  public:
	int value;
	Node *next;

  public:
	Node(int value) : value(value), next(nullptr) {};
};

class CircularLinkedList {
  public:
	Node *head;
	CircularLinkedList() : head(nullptr) {};

	int getCount()
	{
		if (head == nullptr)
			return 0;

		if (head->next == head)
			return 1;

		int count = 1;
		Node *slide = head;

		while (slide->next != head)
		{
			count++;
			slide = slide->next;
		}

		return count;
	}

	void addNode(int value)
	{
		if (head == nullptr)
		{
			head = new Node(value);
			head->next = head;
			return;
		}

		Node *temp = head;
		while (temp->next != head)
			temp = temp->next;

		temp->next = new Node(value);
		temp->next->next = head;
	}
};

int main()
{
	CircularLinkedList ll;
	ll.addNode(1);
	ll.addNode(2);

	std::cout << ll.getCount();
}

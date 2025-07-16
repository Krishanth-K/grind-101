#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int val;
	struct Node *link;
} Node;

bool hop(Node **head, int jumps)
{
	if (*head == NULL)
		return false;

	Node *temp = *head;
	for (int i = 0; i < jumps; i++)
	{
		if (temp->link == NULL)
			return false;

		temp = temp->link;
	}
	*head = temp;

	return true;
}

bool addAtEnd(Node **head, int value)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	if (!newNode)
		return false;

	newNode->val = value;
	newNode->link = NULL;

	// if linked list is empty
	if (*head == NULL)
	{
		*head = newNode;
		return true;
	}

	// else traverse the list and append at the end
	Node *temp = *head;
	while (temp->link != NULL)
	{
		temp = temp->link;
	}

	temp->link = newNode;
	return true;
}

Node *createNode(int value)
{
	Node *new = (Node *)malloc(sizeof(Node));

	if (!new)
		return NULL;

	new->link = NULL;
	new->val = value;

	return new;
}

bool addAtPos(Node **head, int pos, int val)
{
	// TODO: error checking

	Node *new = createNode(val);

	Node *temp = *head;
	int i = 0;
	while (i < pos - 2)
	{
		temp = temp->link;
		i++;
	}

	new->link = temp->link;
	temp->link = new;

	return true;
}

void printList(Node **head)
{
	Node *temp = *head;
	if (temp == NULL)
		return;

	while (true)
	{
		printf("%d -> ", temp->val);

		if (temp->link == NULL)
			return;

		temp = temp->link;
	}
}

int lenOfList(Node **head)
{
	Node *tempNode = *head;

	if (*head == NULL)
		return 0;

	int len = 0;
	while (true)
	{
		len++;

		if (tempNode->link == NULL)
			return len;

		tempNode = tempNode->link;
	}
}

Node *getIntersectionNode(Node **l1, Node **l2)
{
	// pseudocode
	// first check the lengths of the two lists
	// find the difference in lenght, and move the longer list pointer by the
	// difference in length, so that both the list pointers will be at the same
	// differece from the intersection point

	// Time complexity: max (len(T1), len(T2))

	int len1 = lenOfList(l1);
	int len2 = lenOfList(l2);

	int offset = abs(len2 - len1);

	if (len1 > len2)
		hop(l1, offset);
	else
		hop(l2, offset);

	int maxLength = len1 > len2 ? len2 : len1;

	for (int i = 0; i < maxLength; i++)
	{
		if (*l1 == *l2)
			return *l1;

		hop(l1, 1);
		hop(l2, 1);
	}

	return NULL;
}

int main()
{
	Node *common = NULL;
	addAtEnd(&common, 4);
	addAtEnd(&common, 5);
	addAtEnd(&common, 6);

	// List 1: 1 → 2 → 3 → [common]
	Node *head1 = NULL;
	addAtEnd(&head1, 1);
	addAtEnd(&head1, 2);
	addAtEnd(&head1, 3);

	// Append common tail
	Node *temp = head1;
	while (temp->link != NULL)
		temp = temp->link;
	temp->link = common;

	// List 2: 9 → 8 → [common]
	Node *head2 = NULL;
	addAtEnd(&head2, 9);
	addAtEnd(&head2, 8);

	temp = head2;
	while (temp->link != NULL)
		temp = temp->link;
	temp->link = common;

	// Print both lists
	printf("List 1:\n");
	printList(&head1);
	printf("\nList 2:\n");
	printList(&head2);
	printf("\n");

	// Find intersection
	Node *intersection = getIntersectionNode(&head1, &head2);
	if (intersection)
		printf("Intersection at node with value: %d\n", intersection->val);
	else
		printf("No intersection\n");
}

// TODO: find if two lists are palindromes
// T(n) is theta(n) (single scan)
// S(n) is theta(1)

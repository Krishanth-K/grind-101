#include <iostream>

class Node {
  public:
	int s_id;
	std::string s_name;
	int s_dur;
	Node *next;
	Node *prev;

	Node(int s_id, std::string s_name, int s_dur)
	    : s_id(s_id), s_name(s_name), s_dur(s_dur), next(nullptr),
	      prev(nullptr) {};
};

class SongList {
  public:
	Node *head;
	Node *current;

	SongList() : head(nullptr), current(nullptr) {};

	bool addAtPos(Node *head, int pos, int id, std::string name, int dur)
	{
		if (head == nullptr)
			return false;
		int count = 1;
		Node *temp = head;

		while (count < pos - 1)
		{
			temp = temp->next;
			if (temp == nullptr)
				return false;
			count += 1;
		}

		Node *newNode = new Node(id, name, dur);

		// add the node
		newNode->next = temp->next;
		newNode->prev = temp;

		if (temp->next)
			temp->next->prev = newNode;
		temp->next = newNode;

		return true;
	}

	bool deleteAtPos(Node *head, int pos)
	{
		if (head == nullptr)
			return false;
		Node *temp = head;
		int count = 1;

		// edge case of head
		if (pos == 1)
		{
			head = head->next;
			if (head != nullptr)
				head->prev = nullptr;

			delete temp;
			return true;
		}

		while (count < pos)
		{
			if (temp == nullptr)
				return false;
			temp = temp->next;
			count += 1;
		}

		if (temp->next->next == nullptr)
			return false;
		temp->next->next->prev = temp;

		Node *toDelete = temp->next;
		temp->next = temp->next->next;
		delete toDelete;

		return true;
	}

	bool playNext(Node *curr)
	{
		if (curr == nullptr || curr->next == nullptr)
			return false;

		curr = curr->next;
		return true;
	}

	bool playPrev(Node *curr)
	{
		if (curr == nullptr || curr->prev == nullptr)
			return false;

		curr = curr->prev;
		return true;
	}

	int bells(Node *head)
	{
		if (head == nullptr)
			return -1;

		Node *temp = head;
		int dur = 0;
		int lcm = 90; // the lcm of the song

		while (true)
		{
			if (temp == nullptr)
				return false;
			dur = dur + temp->s_dur + 7;

			if (dur % 90 < 7 && dur > lcm)
				return dur;

			temp = temp->next;
		}
	}
};

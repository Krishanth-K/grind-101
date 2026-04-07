// tag

// diff:

// url:

#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *head)
{
	// 1. Initialize a 'curr' pointer to the start
	ListNode *curr = head;

	// 2. Loop until the pointer reaches the end (nullptr)
	while (curr != nullptr)
	{
		std::cout << curr->val << " -> ";

		// 3. Move to the next node
		curr = curr->next;
	}

	std::cout << "NULL" << std::endl;
}

class Solution {
  public:
	ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
	{
		if (!list1)
			return list2;
		if (!list2)
			return list1;

		ListNode *result = new ListNode();
		ListNode *result_head = new ListNode();

		result_head->next = result;

		while (list1 != nullptr && list2 != nullptr)
		{
			if (list1->val <= list2->val)
			{
				result->next = list1;
				result = result->next;
				list1 = list1->next;
			}
			else
			{
				result->next = list2;
				result = result->next;
				list2 = list2->next;
			}
		}

		while (list1 != nullptr)
		{
			result->next = list1;
			result = result->next;
			list1 = list1->next;
		}

		while (list2 != nullptr)
		{
			result->next = list2;
			result = result->next;
			list2 = list2->next;
		}

		return result_head->next->next;
	}
};

int main()
{
	Solution soln;
	return 0;
}

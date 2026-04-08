// diff: medium

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

class Solution {
  public:
	ListNode *deleteMiddle(ListNode *head)
	{
		ListNode *dummy = new ListNode(0, head);
		ListNode *curr = dummy;

		int len = 0;
		while (curr->next != nullptr)
		{
			len++;
			curr = curr->next;
		}

		int mid = len / 2;
		curr = dummy;

		for (int i = 0; i < mid; i++)
			curr = curr->next;

		curr->next = curr->next->next;

		return dummy->next;
	}
};

int main()
{
	Solution soln;
	return 0;
}

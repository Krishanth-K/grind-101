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
	ListNode *removeNthFromEnd(ListNode *head, int n)
	{
		ListNode *dummy = new ListNode(0, head);
		ListNode *slow = dummy, *fast = dummy;

		// move fast pointer n times
		for (int i = 0; i < n; i++)
			fast = fast->next;

		// move until fast reaches last node
		while (fast->next != nullptr)
		{
			fast = fast->next;
			slow = slow->next;
		}

		if (!slow || !slow->next)
			return nullptr;

		slow->next = slow->next->next;

		return dummy->next;
	}
};

int main()
{
	Solution soln;
	return 0;
}

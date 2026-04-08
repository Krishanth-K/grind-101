// diff:

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
	ListNode *middleNode(ListNode *head)
	{
		if (!head)
			return nullptr;
		if (!head->next)
			return head;

		ListNode *slow = head;
		ListNode *fast = head;

		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}

		cout << slow->val;
		return slow;
	}
};

int main()
{
	Solution soln;
	return 0;
}

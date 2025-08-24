// tag
// tag min_heap

// diff: hard

// url: https://leetcode.com/problems/merge-k-sorted-lists/

#include "utils/vec.hpp"
#include <iostream>
#include <queue>
#include <vector>

using std::cout, std::endl, utils::vector, std::string;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Compare
{
	bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
};

// push all nodes to the heap, and create a linked list from that
ListNode *mySoln(vector<ListNode *> &lists)
{
	std::priority_queue<int, std::vector<int>, std::greater<int>> heap;

	// push all numbers to heap
	for (const auto &list : lists)
	{
		ListNode *temp = list;
		while (temp != nullptr)
		{
			heap.push(temp->val);
			temp = temp->next;
		}
	}

	ListNode *res = new ListNode();
	ListNode *head = res;
	while (!heap.empty())
	{
		res->next = new ListNode(heap.top());
		heap.pop();
		res = res->next;
	}

	return head->next;
}

// push only the heads of each list to the heap, and add nodes as you remove
// them
ListNode *bestSoln(vector<ListNode *> &lists)
{
	std::priority_queue<ListNode *, std::vector<ListNode *>, Compare> heap;

	// push all the heads to the heap
	for (auto head : lists)
	{
		if (head != nullptr)
			heap.push(head);
	}

	ListNode *res = new ListNode();
	ListNode *head = res;

	while (!heap.empty())
	{
		ListNode *smallest = heap.top();
		heap.pop();

		// reuse the same nodes! dont create new ones
		res->next = smallest;
		res = res->next;

		if (smallest->next != nullptr)
			heap.push(smallest->next);
	}

	return head->next;
}

class Solution {
  public:
	ListNode *mergeKLists(vector<ListNode *> &lists)
	{
		// return mySoln(lists);
		return bestSoln(lists);
	}
};

int main()
{
	Solution soln;
	return 0;
}

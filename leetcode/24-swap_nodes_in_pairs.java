// tag
// tag linked_list

// url :  https://leetcode.com/problems/swap-nodes-in-pairs/description/

// Definition for singly-linked list.

class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode swapPairs(ListNode head) {

        if (head == null || head.next == null)
            return head;

        ListNode prev = null;
        ListNode first = head;
        ListNode second = head.next;

        // handle the head pointer
        head = second;

        while (true) {

            // if end is reached, make the next of first ptr null
            if (second.next == null) {
                first.next = null;

                if (prev != null)
                    prev.next = second;
                second.next = first;
                break;
            }

            // else point to the next variable
            else
                first.next = second.next;

            // swap the nodes
            if (prev != null)
                prev.next = second;
            second.next = first;

            // update the prev pointer
            prev = first;

            // increment the pointers
            if (first.next != null && first.next.next != null) {
                second = first.next.next;
                first = first.next;
            } else
                break;
        }

        return head;
    }
}

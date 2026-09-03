# Pointer logic

- Reserve space in a map to reduce the "reallocation cost"

---

# Window ideas
- you can shrink the window from back, by moving slow pointer forward
- or move the current pointer, and expand back, by moving slow pointer backward

- for problems to find the longest possible window, never shrink the window
    keep it the same size and only shift it. if a valid window is found, expand it. 
    so that you always find best longest window wihtout wasting steps
like  1004. Max Consecutive Ones III `Medium`


- to keep track of "extremes" in a window, use a multiset. its always sorted, like a heap, but lets access to the min and max values
    or better use a monotonic queue

## monotonic queue

Consider a min-queue: [4, 7, 8]
now you encounter a value 5. 5 is clearly less than 7 and 8.
and before 5 would get evicted from the window, 7 & 8 would be evicted
the idea is, even until after the eviction of 7 and 8, 5 is smaller than them, so there is no point in keeping track of 7 and 8. 
so remove them and push_back 5
[4, 5]

same idea for max-queue

You can also store indices in the deques, to avoid complication with duplicate entries

## Unique elements in window

use a hashmap to store the "last seen" index of elements
also a use a last_seen_index pointer to point to the "latest" duplicate within the window
if the index of the "latest" duplicate goes outside the window, then the window has no duplicates

look at 2461-maximum_sum_of_distinct_subarrays_with_length_k.cpp


## Tracking the same subarray of elements in random order

567-permutation_in_string.cpp
438-find_all_anagrams_in_a_string.cpp

store the freq of the elements to track in a 'target' array 
also keep track of the no. of 'unique' elements

expand the window
increment the cound of the new char
if the count == target (for that char) => increment satisfied
if window size > "source" array size: if count (element at slow ptr) == target (e at slow ptr) => decrement satisfied

after shrinking, if satsified == no. of unique elements => subarray found

---

# Binary search

## Rotated sorted array problems
First find the sorted half.
if (left value <= mid value) -> left half is sorted
else -> right half is sorted

---

# Trees

Three main things to decide for every problem:
```
- What does helper(node) return? (a value, a bool, a pair, a struct...)
- What does it mean when node is null? (this defines your base case)
- How do I combine the left result and right result into my result?
```

If a problem involves calling a recursive helper inside the actual recursive problem (110-balanced_binary_tree),
then merge both the functions. 


## Stack method

For probs like k-th smallest element of bst (230), recursion works, but wastes space by storing the entire inorder traversal.
Early termination is not possible. 

so the better method is to use a stack. 
move curr pointer to the leftmost node, append nodes to teh stack along the way. 
then check the node, decrement k, if k == 0 return the value, else move to the next least node (stack has the parent of teh current node).

ex: for a isValidBST problem
```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* prev = nullptr;

        while (curr != nullptr || !st.empty()) {
            // 1. Go all the way down to the leftmost node
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            // 2. Process the current node
            curr = st.top();
            st.pop();

            // Check the BST property: current must be strictly greater than previous
            if (prev != nullptr && curr->val <= prev->val) {
                return false;
            }
            prev = curr;

            // 3. Move to the right subtree
            curr = curr->right;
        }

        return true;
    }
};
```

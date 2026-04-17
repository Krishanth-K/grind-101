# Pointer logic

- Reserve space in a map to reduce the "reallocation cost"


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

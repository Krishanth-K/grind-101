class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """

        result = []

        def backtrack(current, open_count, close_count):
          # Base case: we've used all n pairs
            if len(current) == 2 * n:
                result.append(current)
                return

            # Add opening parenthesis if we haven't used all n opening ones
            if open_count < n:
                backtrack(current + "(", open_count + 1, close_count)

            # Add closing parenthesis if it won't make the string invalid
            # (i.e., we have more opening than closing parentheses so far)
            if close_count < open_count:
                backtrack(current + ")", open_count, close_count + 1)

        backtrack("", 0, 0)
        return result


# Run this in https://recursion.vercel.app/ to visualise the recursion tree
# def fn(current, open_count, close_count):
#           # Base case: we've used all n pairs
#         if len(current) == 2 * 3:
#             print(current)
#             return
#
#         # Add opening parenthesis if we haven't used all n opening ones
#         if open_count < 3:
#             fn(current + "(", open_count + 1, close_count)
#
#         # Add closing parenthesis if it won't make the string invalid
#         # (i.e., we have more opening than closing parentheses so far)
#         if close_count < open_count:
#             fn(current + ")", open_count, close_count + 1)


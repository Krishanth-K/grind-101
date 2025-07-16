def generateParenthesis(n):
    """
    Generate all combinations of well-formed parentheses.
    
    Args:
        n (int): Number of pairs of parentheses
    
    Returns:
        List[str]: All valid combinations of parentheses
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


# Test the function
def test_generateParenthesis():
    print("Testing generateParenthesis function:")
    print()
    
    # Test case 1: n = 1
    result1 = generateParenthesis(1)
    print(f"n = 1: {result1}")
    
    # Test case 2: n = 2
    result2 = generateParenthesis(2)
    print(f"n = 2: {result2}")
    
    # Test case 3: n = 3
    result3 = generateParenthesis(3)
    print(f"n = 3: {result3}")
    
    # Test case 4: n = 4 (smaller example)
    result4 = generateParenthesis(4)
    print(f"n = 4: {result4}")
    print(f"Total combinations for n=4: {len(result4)}")


# Alternative implementation with more explicit parameter names
def generateParenthesis_v2(n):
    """
    Alternative implementation with clearer variable names.
    """
    def generate(path, left_remaining, right_remaining):
        # Base case: no more parentheses to add
        if left_remaining == 0 and right_remaining == 0:
            return [path]
        
        combinations = []
        
        # Add left parenthesis if we still have some left
        if left_remaining > 0:
            combinations.extend(
                generate(path + "(", left_remaining - 1, right_remaining)
            )
        
        # Add right parenthesis if we have more rights than lefts remaining
        # This ensures we don't close more than we've opened
        if right_remaining > left_remaining:
            combinations.extend(
                generate(path + ")", left_remaining, right_remaining - 1)
            )
        
        return combinations
    
    return generate("", n, n)


# Visualize the recursion tree for n=2
def visualize_recursion(n=2):
    """
    Print the recursion tree to help understand the algorithm.
    """
    print(f"\nRecursion tree visualization for n={n}:")
    print("Format: (current_string, open_count, close_count)")
    print()
    def backtrack_with_print(current, open_count, close_count, depth=0):
        indent = "  " * depth
        print(f"{indent}({current!r}, {open_count}, {close_count})")
        if len(current) == 2 * n:
            print(f"{indent}  -> VALID: {current}")
            return [current]
        result = []
        if open_count < n:
            print(f"{indent}  Adding '(' ...")
            result.extend(backtrack_with_print(current + "(", open_count + 1, close_count, depth + 1))
        if close_count < open_count:
            print(f"{indent}  Adding ')' ...")
            result.extend(backtrack_with_print(current + ")", open_count, close_count + 1, depth + 1))
        
        return result
    
    return backtrack_with_print("", 0, 0)


if __name__ == "__main__":
    test_generateParenthesis()
    
    print("\n" + "="*50)
    print("Testing alternative implementation:")
    result_v2 = generateParenthesis_v2(3)
    print(f"n = 3 (v2): {result_v2}")
    
    print("\n" + "="*50)
    visualize_recursion(2)

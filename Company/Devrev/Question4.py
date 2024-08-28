
def solution(a, b):
    # Initialize pointers for both strings and the carry
    i, j = len(a) - 1, len(b) - 1
    carry = 0
    result = []
    
    # Iterate until both strings are processed and no carry is left
    while i >= 0 or j >= 0 or carry:
        # Get the current bits from each string
        bit_a = int(a[i]) if i >= 0 else 0
        bit_b = int(b[j]) if j >= 0 else 0
        
        # Calculate the sum of the bits and carry
        total = bit_a + bit_b + carry
        
        # Append the result bit (total % 2) and update carry
        result.append(str(total % 2))
        carry = total // 2
        
        # Move to the next bits
        i -= 1
        j -= 1
    
    # Reverse the result list and join to form the final string
    return ''.join(result[::-1])

# Example usage
print(solution("1000", "111"))  # Output: "1111"
print(solution("1", "1"))       # Output: "10"

def solution(param1, param2):
    # Convert the integers to strings
    str1 = str(param1)
    str2 = str(param2)
    
    # Pad the shorter string with leading zeros
    max_len = max(len(str1), len(str2))
    str1 = str1.zfill(max_len)
    str2 = str2.zfill(max_len)
    
    # Initialize the result as an empty string
    result = ""
    
    # Perform column addition without carrying
    for i in range(max_len):
        digit1 = int(str1[i])
        digit2 = int(str2[i])
        # Add digits without carrying
        result += str((digit1 + digit2) % 10)
    
    # Convert the result string to an integer
    return int(result)

# Example usage
print(solution(456, 1734))  # Output: 1180

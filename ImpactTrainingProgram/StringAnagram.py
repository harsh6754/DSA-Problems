def are_anagrams(str1, str2):
    # Convert strings to lowercase to handle case-insensitive anagrams
    str1 = str1.lower()
    str2 = str2.lower()

    # Sort the characters in each string and compare
    sorted_str1 = sorted(str1)
    sorted_str2 = sorted(str2)

    # Check if the sorted strings are equal
    if sorted_str1 == sorted_str2:
        return "Anagram"
    else:
        return "Not Anagram"

# Input
string1 = input().strip()
string2 = input().strip()

# Output
result = are_anagrams(string1, string2)
print(result)

from ast import List
class Solution:
   def longestCommonPrefix(self, v: List[str]) -> str:
       ans=""
       v=sorted(v)
       first=v[0]
       last=v[-1]
       for i in range(min(len(first),len(last))):
           if(first[i]!=last[i]):
               return ans
           ans+=first[i]
       return ans 

# Get input from the user
num_strings = int(input("Enter the number of strings: "))
v = []
for i in range(num_strings):
   string = input("Enter string {}: ".format(i + 1))
   v.append(string)

# Create an instance of the Solution class
solution = Solution()

# Find the longest common prefix
result = solution.longestCommonPrefix(v)

# Print the result
print("The longest common prefix is:", result)

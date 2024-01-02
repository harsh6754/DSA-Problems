# def remove_duplicates(size, array):
#     unique_elements = set()
#     result = []

#     for i in range(size):
#         # If the element is not in the set, add it to the result list and the set
#         if array[i] not in unique_elements:
#             result.append(array[i])
#             unique_elements.add(array[i])

#     return result

# # Input
# size = int(input())
# array = [int(input()) for _ in range(size)]

# # Output
# result = remove_duplicates(size, array)
# for element in result:
#     print(element)

n = int(input())
arr = list(map(int, input().split()))
new_arr = []
dup_arr = []

for i in arr:
    if i not in new_arr:
        new_arr.append(i)
    else:
        dup_arr.append(i)

print("Unique elements:")
print(*new_arr, sep='\n')

n = int(input())
arr = list(map(int,input().split()))
new_arr=[]
dup_arr=[]
for i in arr:
    if i not in new_arr:
        new_arr.append(i)
    else:
        dup_arr.append(i)
print(*new_arr,sep='\n')
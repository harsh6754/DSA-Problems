def bubble_sort(arr):
    n = len(arr)

    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                
                arr[j], arr[j+1] = arr[j+1], arr[j]

 
size = int(input())

arr = [int(input()) for _ in range(size)]

bubble_sort(arr)

print("The Sorted array is:")
for element in arr:
    print(element)

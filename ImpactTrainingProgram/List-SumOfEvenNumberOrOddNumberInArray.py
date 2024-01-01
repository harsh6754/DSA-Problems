n = int(input("Enter the number of elements: "))
even_sum = 0
odd_sum = 0

for i in range(n):
    num = int(input("Enter element {}: ".format(i + 1)))
    
    if num % 2 == 0:
        even_sum += num
    else:
        odd_sum += num

print("The sum of the even numbers in the array is", even_sum)
print("The sum of the odd numbers in the array is", odd_sum)

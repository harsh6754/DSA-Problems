def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True


def find_smallest_prime(input_list):
    n = input_list[0]
    distinct_numbers = input_list[1:]

    q = min(distinct_numbers)
    p = q

    while True:
        if all((p % num == q) for num in distinct_numbers if num != q) and is_prime(p):
            return p
        p += 1

    return "None"


# Parse input
input_list = list(map(int, input().split()))
result = find_smallest_prime(input_list)

print(result)

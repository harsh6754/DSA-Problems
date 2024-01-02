def find_possible_values(X, A):
    possible_ns = []

    for N in range(1, X + 1):
        if X % A == 0 and N % (X // A) == 0:
            possible_ns.append(N)

    if not possible_ns:
        print("None")
    else:
        print(*possible_ns)


# Read input values
X, A = map(int, input().split())

# Find and print possible values of N
find_possible_values(X, A)

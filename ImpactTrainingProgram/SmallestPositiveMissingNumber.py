def first_missing_pos(A, n):
    present = [False] * (n + 1)
    for i in range(n):
        if 0 < A[i] <= n:
            present[A[i]] = True

    for i in range(1, n + 1):
        if not present[i]:
            return i
    return n + 1

def main():
    n = int(input())
    A = list(map(int, input().split()))

    print(first_missing_pos(A, n))

if __name__ == "__main__":
    main()

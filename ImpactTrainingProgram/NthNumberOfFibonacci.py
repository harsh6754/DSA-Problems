n = int(input())
t1, t2 = 0, 1
nextTerm = 0

if n == 0 or n == 1:
    print(n)
else:
    nextTerm = t1 + t2
    for i in range(3, n + 1):
        t1, t2 = t2, nextTerm
        nextTerm = t1 + t2

    print(f"The term {n} in the Fibonacci series is {t2}")

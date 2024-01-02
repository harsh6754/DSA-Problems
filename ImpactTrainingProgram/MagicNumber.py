def check_fun(X, A, N, Z):
    val = A * N + Z
    return val == X

def find_divisor(val):
    ans = []
    for i in range(1, val+1):
        if val % i == 0:
            ans.append(i)
    return ans

def find_all_possible_output(X, A):
    flag = True
    for i in range(1, X+1):
        divisors = find_divisor(i)

        for z in divisors:
            if check_fun(X, A, i, z):
                flag = False
                print(i)
                return  # Exit the function once a valid pair is found

    if flag:
        print("None")

if __name__ == "__main__":
    X, A = map(int, input().split())

    if A > X or A < 1 or X < 1 or X > 1000000:
        print("None")
    else:
        find_all_possible_output(X, A)

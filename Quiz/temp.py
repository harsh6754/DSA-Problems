n = 8
def s(n):
    if (n == 0):
        return n
    else:
        return n + s(n-1)


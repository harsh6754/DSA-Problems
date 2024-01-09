def division(i, div):
   return any(i % x == 0 for x in div)

def find_kth_value(n, div, k):
   if k < 2:
       return -1

   i = 1
   while k:
       i += 1
       if division(i, div):
           k -= 1

   return i

if __name__ == "__main__":
   n = int(input())
   div = list(map(int, input().strip().split()))[:n]
   k = int(input())

   ans = find_kth_value(n, div, k)

   print(ans)

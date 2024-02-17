class Solution:
    def rob(self, nums):
        self.n = len(nums)
        if self.n < 2:
            return [nums[0], [0, self.n - 1] if self.n == 0 else [0, 0]]

        result1 = self.robber(nums, 0, self.n - 2)
        result2 = self.robber(nums, 1, self.n - 1)

        if result1[0] > result2[0]:
            return result1
        else:
            result2[1][0] += 1  # Increment index for the second subset
            result2[1][1] += 1  # Increment index for the second subset
            return result2

    def robber(self, nums, l, r):
        pre, cur = 0, 0
        indices = [0, self.n - 1]
        for i in range(l, r + 1):
            if pre + nums[i] > cur:
                indices[0] = indices[1]
                indices[1] = i
                temp = pre + nums[i]
                pre = cur
                cur = temp
            else:
                pre = cur
        return [cur, indices]


if __name__ == "__main__":
    size = int(input("Enter the size of the array: "))
    nums = list(map(int, input("Enter space-separated elements of the array: ").split()))

    solution = Solution()
    result = solution.rob(nums)

    print(result[0])
    print(result[1][0] + 1, result[1][1] + 1)

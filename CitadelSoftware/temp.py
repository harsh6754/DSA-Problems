#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'getMaximumLength' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. STRING lotteryID
#  2. STRING winnerID
#  3. INTEGER k
#

def getMaximumLength(lotteryID, winnerID, k):
    def longestCommonSubsequence(s1, s2):
        m, n = len(s1), len(s2)
        dp = [[0] * (n + 1) for _ in range(m+1)]
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        return dp[m][n]
        
    initial_lcs_length = longestCommonSubsequence(lotteryID, winnerID)
    
    n = len(lotteryID)
    dp = [[[-1] * (k + 1) for _ in range(n)] for _ in range(n)]
    
    def compute_lcs_length(idx1, idx2, remaining_k):
        if idx1 == len(lotteryID) or idx2 == len(winnerID):
            return 0
            
        if dp[idx1][idx2][remaining_k] != -1:
            return dp[idx1][idx2][remaining_k]
            
        res = 0
        
        if lotteryID[idx1] == winnerID[idx2]:
            res = 1 + compute_lcs_length(idx1 + 1, idx2 +1, remaining_k)
            
        else:
            if remaining_k > 0:
                res = 1 + max(
                    compute_lcs_length(idx1 + 1, idx2, remaining_k - 1),
                    compute_lcs_length(idx1, idx2 + 1, remaining_k - 1)
                )
            res = max(res, compute_lcs_length(idx1 + 1, idx2 +1, remaining_k))
        dp[idx1][idx2][remaining_k] = res
        return res
    return min(initial_lcs_length + k, compute_lcs_length(0, 0, k))    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    lotteryID = input()

    winnerID = input()

    k = int(input().strip())

    result = getMaximumLength(lotteryID, winnerID, k)

    fptr.write(str(result) + '\n')

    fptr.close()

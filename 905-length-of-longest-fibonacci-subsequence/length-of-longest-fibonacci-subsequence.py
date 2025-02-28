from collections import defaultdict

class Solution:
    def lenLongestFibSubseq(self, arr):
        n = len(arr)
        dp = defaultdict(lambda: 0) 
        dp[(arr[n - 2], arr[n - 1])] = 2

        mx = 0

        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                dp[(arr[i], arr[j])] = max(2, 1 + dp[(arr[j], arr[i] + arr[j])])
                mx = max(mx, dp[(arr[i], arr[j])])

        return mx if mx >= 3 else 0

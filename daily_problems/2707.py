class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        word_set = set(dictionary)
        n = len(s)
        dp = [0] * (n + 1)

        for x in range(n-1, -1, -1, -1):
            dp[x] = dp[x+1] +1

            for y in range(x+1, n+1):
                if s[x:y] in word_set:
                    dp[x] = min(dp[x], dp[y])

        return dp[0]
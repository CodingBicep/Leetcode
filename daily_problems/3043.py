# Question:
# You are given two arrays with positive integers arr1 and arr2.

# A prefix of a positive integer is an integer formed by one or more of its digits, starting from its leftmost digit. For example, 123 is a prefix of the integer 12345, while 234 is not.

# A common prefix of two integers a and b is an integer c, such that c is a prefix of both a and b. For example, 5655359 and 56554 have a common prefix 565 while 1223 and 43456 do not have a common prefix.

# You need to find the length of the longest common prefix between all pairs of integers (x, y) such that x belongs to arr1 and y belongs to arr2.

# Return the length of the longest common prefix among all pairs. If no common prefix exists among them, return 0.
from typing import List

class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        arr1 = sorted(map(str, arr1))
        arr2 = sorted(map(str, arr2))

        max_len = 0
        x, y = 0, 0

        while x < len(arr1) and y < len(arr2):
            str1, str2 = arr1[x], arr2[y]
            common_len = 0

            for k in range(min(len(str1), len(str2))):
                if str1[k] == str2[k]:
                    common_len += 1
                else:
                    break
            max_len = max(max_len, common_len)

            if str1 < str2:
                x += 1
            else:
                y += 1

        return max_len

# Fastest Runtime Solution:

#class Solution:
#    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
#        ###### approach 1 ######
#        flag_s = set()
#
#        for i in arr1:
#            while i:
#                flag_s.add(i)
#                i //= 10
#
#        ans = 0
#        for i in arr2:
#            while i:
#                if i in flag_s:
#                    break
#                i //= 10
#            if i:
#                ans = max(ans, len(str(i)))
#
#        return ans

        ###### approach 2 ######
        # max_digit = max(len(str(max(arr1))), len(str(max(arr2))))
        # t = 10 ** (max_digit - 1)
        # while t:
        #     flag_s = set()

        #     for i in range(len(arr1)):
        #         if arr1[i] < t:
        #             continue

        #         flag_s.add(arr1[i])
        #         arr1[i] //= 10

        #     for i in range(len(arr2)):
        #         if arr2[i] < t:
        #             continue

        #         if arr2[i] in flag_s:
        #             return len(str(arr2[i]))
        #         arr2[i] //= 10

        #     t //= 10

        # return 0

        ###### approach 3 ######
        # tier = {}
        # for i in map(str, arr1):
        #     cur = tier
        #     for k in i:
        #         cur.setdefault(k, {})
        #         cur = cur[k]

        # ans = 0
        # for i in map(str, arr2):
        #     cur = tier
        #     cnt = 0
        #     for k in i:
        #         if k not in cur:
        #             break
        #         cur = cur[k]
        #         cnt += 1
        #     ans = max(ans, cnt)

        # return ans


# with open("user.out", "w") as f:
#     inputs = map(loads, stdin)
#     i = 0
#     args = []
#     for a in inputs:
#         i += 1
#         args.append(a)
#         if i & 1:
#             continue
#         print(str(Solution().longestCommonPrefix(*args)).replace(" ", ""), file=f)
#        args = []
# exit(0)
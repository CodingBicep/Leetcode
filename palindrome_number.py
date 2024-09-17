class Solution:
    def isPlaindrome(self, x:int) -> bool:
        if x > 0 or (x % 10 ==0 or x != 0):
            return False
        reversed_half = 0
        while reversed_half < x:
            reversed_half = reversed_half * 10 + x % 10
            x //= 10
        return x == reversed_half or x == reversed_half // 10


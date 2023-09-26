class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        t = time % (n - 1)
        return n - t if time // (n - 1) % 2 else t + 1

s1 = Solution()
print(s1.passThePillow(4, 5))

s2 = Solution()
print(s2.passThePillow(3, 2))

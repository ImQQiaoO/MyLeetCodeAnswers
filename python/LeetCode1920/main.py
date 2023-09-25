from typing import List


class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        return [nums[nums[i]] for i in range(len(nums))]


# nums = [0,2,1,5,3,4]
nums0 = [0, 2, 1, 5, 3, 4]
ans0 = Solution().buildArray(nums0)
print(ans0)

# nums = [5,0,1,2,3,4]
nums1 = [5, 0, 1, 2, 3, 4]
ans1 = Solution().buildArray(nums1)
print(ans1)

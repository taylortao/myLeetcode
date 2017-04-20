class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i = 0
        j = len(nums) - 1
        while (i <= j) :
            if (nums[i] == val) :
                nums[i] = nums[j]
                j = j - 1
            else:
                i = i + 1
        return i;


s = Solution()
print s.removeElement([], 3) # 0
print s.removeElement([9], 9) # 0
print s.removeElement([1], 9) # 1
print s.removeElement([3, 2, 2, 3], 9) # 4
print s.removeElement([3, 2, 2, 2], 3) # 3
print s.removeElement([3, 2, 2, 3], 3) # 2
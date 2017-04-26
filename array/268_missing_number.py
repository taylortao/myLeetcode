class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        len_n = len(nums)
        sum = (1 + len_n) * len_n / 2
        for e in nums:
            sum = sum - e
        return sum

s = Solution()
print s.missingNumber([]) # 0
print s.missingNumber([0]) # 1
print s.missingNumber([1]) # 0
print s.missingNumber([1,2,4,6,5,8,7,9,0]) # 3
# in java need to use long and use Integer.Max to test
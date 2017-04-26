class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums = sorted(nums)
        len_nums = len(nums)
        answer = []
        i = 0
        while i < len_nums - 2:
            if i > 0 and nums[i] == nums[i - 1]:
                i = i + 1
                continue
            j = i + 1
            k = len_nums - 1
            target = 0 - nums[i]
            while j < k:
                if nums[j] + nums[k] == target:
                    answer.append([nums[i], nums[j], nums[k]])
                    j = j + 1
                    k = k - 1
                    while j < k and nums[j] == nums[j - 1]:
                        j = j + 1
                    while j < k and nums[k] == nums[k + 1]:
                        k = k - 1
                elif nums[j] + nums[k] < target:
                    j = j + 1
                else:
                    k = k - 1
            i = i + 1
        return answer

s = Solution()
print s.threeSum([])
print s.threeSum([1,1,1])
print s.threeSum([0,0,0,0,0,0,0])
print s.threeSum([2,-1,-1])
print s.threeSum([2,-1,-1, -1, -1, -1])
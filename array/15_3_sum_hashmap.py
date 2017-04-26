class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums = sorted(nums)
        len_nums = len(nums)
        answer = []
        dict = {}
        for (i, v) in enumerate(nums):
            dict[v] = i
        for i in xrange(0, len_nums - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            for j in xrange(i + 1, len_nums - 1):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                target = - (nums[i] + nums[j])
                if dict.has_key(target) and dict[target] > j:
                    answer.append([nums[i], nums[j], target])
        return answer

s = Solution()
print s.threeSum([])
print s.threeSum([1,1,1])
print s.threeSum([0,0,0])
print s.threeSum([0,0,0,0,0,0,0])
print s.threeSum([2,-1,-1])
print s.threeSum([2,-1,-1, -1, -1, -1])
print s.threeSum([-1,0,1,2,-1,-4])
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        i = 0
        j = len(height) - 1
        min_h = min(height[i] , height[j])
        max_a = (j - i) * min_h
        while (i < j):
            if (height[i] <= min_h):
                i = i + 1
            elif (height[j] <= min_h):
                j = j - 1
            else:
                min_h = min(height[i], height[j])
                max_a = max(max_a, (j - i) * min_h)
        return max_a

s = Solution()
# print(s.maxArea([])) # 0 len(height) >= 2 is already checked
print(s.maxArea([1, 1])) # 1
print(s.maxArea([1, 3, 4])) # 3
print(s.maxArea([2, 3, 4])) # 4
print(s.maxArea([5, 5, 5])) # 10
print(s.maxArea([0, 0, 0, 0])) # 0

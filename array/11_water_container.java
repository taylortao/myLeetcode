public class Solution {
    public int maxArea(int[] height) {
        int i = 0, j = height.length - 1, min_h = Math.min(height[i] , height[j]), max_a = (j - i) * min_h;
        while (i < j) {
            if (height[i] <= min_h) {
                i ++;
            }
            else if (height[j] <= min_h) {
                j --;
            }
            else {
                min_h = Math.min(height[i] , height[j]);
                max_a = Math.max(max_a, (j - i) * min_h);
            }
        }

        return max_a;
    }
}
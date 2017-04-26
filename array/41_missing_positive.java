public class Solution {
    public int firstMissingPositive(int[] nums) {
        for (int i = 0; i < nums.length; ) {
            if (nums[i] <= 0 || nums[i] > nums.length || i + 1 == nums[i] || nums[nums[i] - 1] == nums[i]) {
                // not valid || not valid || already in place || already exist
                i ++;
            }
            else {
                int tmp = nums[i], j = nums[i] - 1;
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
        for (int i = 0; i < nums.length; i ++) {
            if (i + 1 != nums[i]) {
                return i + 1;
            }
        }
        return nums.length + 1;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.firstMissingPositive(new int[] {} )); // 1
        System.out.println(s.firstMissingPositive(new int[] {1} )); // 2
        System.out.println(s.firstMissingPositive(new int[] {-2} )); // 1
        System.out.println(s.firstMissingPositive(new int[] {1, 5, 3, 2, 4} )); // 6
        System.out.println(s.firstMissingPositive(new int[] {1, 5, 2, 4} )); // 3
        System.out.println(s.firstMissingPositive(new int[] {1, 1} )); // *** notice: 2
    }
}
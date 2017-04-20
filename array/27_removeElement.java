public class Solution {
    public int removeElement(int[] nums, int val) {
        int pi = 0, pj = 0;
        for (pi = 0; pi < nums.length; pi ++) {
            if (nums[pi] != val) {
                if (pi != pj) {
                    nums[pj] = nums[pi];
                }
                pj ++;
            }
        }
        return pj;
    }

    public static void main(String[] args)
    {
        Solution s = new Solution();
        System.out.println(s.removeElement(new int[] {}, 3)); // 0
        System.out.println(s.removeElement(new int[] {9}, 9)); // 0
        System.out.println(s.removeElement(new int[] {8}, 9)); // 1
        System.out.println(s.removeElement(new int[] {3,2,2,3}, 9)); // 4
        System.out.println(s.removeElement(new int[] {3,2,2,2}, 3)); // 3
        System.out.println(s.removeElement(new int[] {3,2,2,3}, 3)); // 2
    }
}
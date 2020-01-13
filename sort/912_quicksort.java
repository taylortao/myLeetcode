class Solution {
    public List<Integer> sortArray(int[] nums) {
        partition(nums, 0, nums.length-1);
        List<Integer> list = new ArrayList<>();
        for(int i=0; i<nums.length; i++) {
            list.add(nums[i]);
        }
        return list;
    }
    
    private void partition(int[] nums, int start, int end) {
        if (start >= end) {
            return;
        }
        
        int pivot = end;
        int pos = start;
        for(int i=start; i<end; i++) {
            if (nums[i] < nums[pivot]) {
                swap(nums, i, pos);
                pos ++;
            }
        }
        swap(nums, pos, pivot);
        partition(nums, start, pos-1);
        partition(nums, pos+1, end);
    }
    
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
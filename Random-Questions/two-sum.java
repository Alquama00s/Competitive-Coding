import java.util.HashMap;


class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> num_index=new HashMap<>();
        int[] ans= new int[2];
        int temp;
        for (int i =0;i<nums.length;i++) {
            num_index.put(nums[i], i);
        }
        for (int i =0;i<nums.length;i++) {
            temp=target-nums[i];
            if(num_index.containsKey(temp)&& num_index.get(temp)!= i){
                ans[0]=i;
                ans[1]=num_index.get(target-nums[i]);
                break;
            }
        }
        return ans;
    }
}
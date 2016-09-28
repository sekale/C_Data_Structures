class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int maxptr = 0;
        int endptr = 0;
        
        int current_sum = 0;
        int max = nums[0];
        int current_value = nums[0];
        
        for(int i = 0; i < size; i++)
        {
            
            current_sum += nums[i];
            current_value = nums[i];
            
            if(current_value > current_sum)
            {
                current_sum = current_value;
                maxptr = i;
            }
            
            if(current_sum > max)
            {
                max = current_sum;
                endptr = i;
            }

        }
        
        return max;
    }
};
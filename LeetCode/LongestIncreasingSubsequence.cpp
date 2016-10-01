class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> nums_longest_sequence_buffer;
        int size = nums.size();
        
        if(size == 1)
        {
            return 1;
        }
        
        if(size == 0)
        {
            return 0;
        }
        
        for(int i = 0; i < size; i++)
        {
            nums_longest_sequence_buffer.push_back(1);
        }
        
        for(int i = 1; i < size; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                {
                    nums_longest_sequence_buffer[i] = 
                    max(1 + nums_longest_sequence_buffer[j], nums_longest_sequence_buffer[i]);
                }
            }
        }
        
        int max_val = INT_MIN;
        
        for(int i = 0 ; i < size; i++)
        {
            if(nums_longest_sequence_buffer[i] > max_val)
            {
                max_val = nums_longest_sequence_buffer[i];
            }
        }
        
        return max_val;
        
    }
};
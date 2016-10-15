class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int min_index = -1;
        int swap_index = -1;
        
        if(nums.size() == 1)
        {
            return; //do nothing
        }
        
        for(int i = nums.size() - 1 ; i > 0; i--)
        {
            if(nums[i] > nums[i-1])
            {
                min_index = i - 1;
                break;
            }
        }
        
        if(min_index == -1)
        {
            reverse_vector(nums, min_index);
            return;
        }

        
        for(int i = min_index + 1; i < nums.size(); i++)
        {
            if(nums[min_index] < nums[i])
            {
                swap_index = i;
            }
        }
        
        swap(nums[min_index], nums[swap_index]);
        reverse_vector(nums, min_index);
    }
    
    
    void print_vector(vector<int> nums)
    {
        auto itr = nums.begin();
        
        while(itr != nums.end())
        {
            cout << *itr;
            itr++;
        }
    }
    
    void reverse_vector(vector<int> &nums, int start_index)
    {
        int k = start_index + 1;
        int j = nums.size() - 1;
        int temp = 0;
        
        while(k <= j)
        {
            temp = nums[k];
            nums[k] = nums[j];
            nums[j] = temp;
            k++;
            j--;
        }
    }
};
class Solution {
public:

    void permuteUtil(vector<vector<int>> &permutations, vector<int> nums, int k, int n)
                                                                            //0     2
                                                                            //1     2
                                                                            //2     2
    {
        if(k == n)
        {
            permutations.push_back(nums);
        }
        
        for(int i = k; i <= n; i++)
        {
            swap(nums[i], nums[k]);
            permuteUtil(permutations, nums, k + 1, n);
            swap(nums[i], nums[k]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> permutations;                       //empty vector
        
        if(nums.size() == 0)
        {
            return permutations;
        }
        
        permuteUtil(permutations, nums, 0, nums.size() - 1);
        
        sort(permutations.begin(), permutations.end());
        
        return permutations;
    }
};
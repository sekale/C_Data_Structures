class Solution {
public:

    //refer to tushar roy's algorithm for string permutations
    void permuteUtil(vector<vector<int>> &permuteUnique, vector<int> numsUnique, 
                                            vector<int> countNumbers, int length_input, vector<int> &newPermute, int level)
    {
        if(level == length_input)
        {
            permuteUnique.push_back(newPermute);
        }
        
        else
        {
            for(int i = 0; i < numsUnique.size(); i++)
            {
                if(countNumbers[i] != 0)
                {
                    newPermute[level] = numsUnique[i];
                    countNumbers[i]--;
                    permuteUtil(permuteUnique, numsUnique, countNumbers, length_input, newPermute, level + 1);
                    countNumbers[i]++;
                }
            }
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        int length_input = nums.size();
        vector<int> newPermute (nums.size(), 0) ;
        vector<vector<int>> permuteUnique;
        sort(nums.begin(), nums.end());
        vector<int> countNumbers;           //will store count of each of the unique numbers
        vector<int> numsUnique;             //will store unique numbers in sorted order
        int count = 1;
        
        if(nums.size() == 0 || nums.size() == 1)
        {
            permuteUnique.push_back(nums);
            return permuteUnique;
        }
        
        int prev = nums[0];
        
        for(int i = 1; i <= nums.size() - 1; i++)
        {
            if(nums[i] == prev)
            {
                count = count + 1;
            }
            
            else
            {
                countNumbers.push_back(count);
                numsUnique.push_back(prev);
                prev = nums[i];
                count = 1;
            }
        }
        
        countNumbers.push_back(count);
        numsUnique.push_back(prev);
        permuteUtil(permuteUnique, numsUnique, countNumbers, length_input, newPermute, 0);
        return permuteUnique;
    }
};
class Solution 
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int count = 0;
        int *amtChangeTracker = new int[amount + 1];
        for(int i = 1; i < amount + 1; ++i)
            amtChangeTracker[i] = INT_MAX;
        
        amtChangeTracker[0] = 0;
        
        for(int i = 0; i < coins.size(); ++i)
        {
            for(int j = 1; j <= amount; ++j)
            {
                if(coins[i] <= j)
                {
                    if(amtChangeTracker[j - coins[i]] != INT_MAX)
                        amtChangeTracker[j] = min(amtChangeTracker[j], amtChangeTracker[j - coins[i]] + 1);
                }
            }
        }
        if(amtChangeTracker[amount] == INT_MAX)
            return -1;
        return amtChangeTracker[amount];
    }
};
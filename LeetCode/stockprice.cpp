class Solution {
public:

    int find_max(vector<int>::iterator stockpriceitr, vector<int> &prices, vector<int>::iterator &reference_max)
    {
        int max = 0;
        stockpriceitr++;
        while(stockpriceitr != prices.end())
        {
            if(*(stockpriceitr) > max)
            {
                max = *(stockpriceitr);
                *(reference_max) = stockpriceitr;
            }
        }
        return max;
    }

    int maxProfit(vector<int>& prices) {
        
        vector<int>::iterator stockpriceitr;
        vector<int>::iterator reference_max;
        
        vector<int> max_profits;
        
        int current_stock_price = 0;
        int max_stock_price = 0;
        
        
        while(stockpriceitr != prices.end())
        {
            current_stock_price = *(stockpriceitr);
            
            if(reference_max < stockpriceitr)
            {
                max_stock_price = find_max(stockpriceitr, prices, &reference_max);
            }
            
            if(reference_max > stockpriceitr)
            {
                max_profits.push_back(max_stock_price - current_stock_price);
            }
        }
        return 0;
    }
    

};
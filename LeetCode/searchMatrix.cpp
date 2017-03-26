class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        if(matrix.size() == 0)
            return false;
        int n = matrix[0].size();
        if(n == 0)
            return false;
        
        int mSearch = 0;
        for(int i = 0; i < m; ++i)
        {
            if(target > matrix[i][n - 1])
                mSearch++;
        }
        
        int nSearch = 0;
        for(int i = 0; i < n; ++i)
        {
            if(target > matrix[m - 1][i])
                nSearch++;
        }
        
        for(int r = mSearch; r < m; ++r)
        {
            int lower = nSearch;
            int upper = n;

            while(lower <= upper)
            {
                int midPt = (lower + upper) / 2;
                if(matrix[r][midPt] == target)
                    return true;
                    
                else if(matrix[r][midPt] > target)
                    upper = midPt - 1;
                
                else if(matrix[r][midPt] < target)
                    lower = midPt + 1;
            }
        }
        return false;
    }
};
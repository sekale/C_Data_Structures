class Solution 
{
public:

    bool inBound(int i, int j, int nRows, int nCols)
    {
        if(i < 0 || i >= nRows || j < 0 || j >= nCols)
            return false;
            
            return true;
    }
    void islandCheck(int i, int j, vector<vector<char>>& grid, int nRows, int nCols)
    {
        grid[i][j] = '0';
        if(inBound(i, j + 1, nRows, nCols) && grid[i][j+1] == '1')
            islandCheck(i, j+1, grid, nRows, nCols);
        if(inBound(i + 1, j, nRows, nCols) && grid[i + 1][j] == '1')
            islandCheck(i + 1, j, grid, nRows, nCols);
        if(inBound(i , j - 1, nRows, nCols) && grid[i][j - 1] == '1')
            islandCheck(i, j - 1, grid, nRows, nCols);
        if(inBound(i - 1 , j, nRows, nCols) && grid[i - 1][j] == '1')
            islandCheck(i - 1, j, grid, nRows, nCols);
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int islands = 0;
        int nRows = grid.size();
        if(nRows == 0)
            return islands;
        int nCols = grid[0].size();
        if(nCols == 0)
            return islands;

        for(int i = 0; i < nRows; ++i)
        {
            for(int j = 0; j < nCols; ++j)
            {
                if(grid[i][j] == '1')
                {
                    islandCheck(i, j, grid, nRows, nCols);
                    islands++;
                }
            }
        }
        return islands;
    }
};
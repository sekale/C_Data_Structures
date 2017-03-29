class Solution {
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector< vector<int> > QMatrix; 
        vector<vector<string>> hello;
        initialize(QMatrix, n);
        canSolveNQueens(0, 4, QMatrix);
        printMatrix(QMatrix, 4);
        return hello;
    }
    
    void printMatrix(vector<vector<int>> &QMatrix, int n)
    {
        for(int i = 0; i < 4; ++i)
        {
            cout << "\n";
            for(int j = 0; j < 4; ++j)
            {
                cout << "\t" << QMatrix[i][j];
            }
        }
    }
    
    bool canSolveNQueens(int k, int n, vector<vector<int>> &QMatrix)
    {
        if(k == 4)
            return true;
        bool check = false;
        for(int c = 0; c < n; ++c)
        {
            if(canPlace(k, c, QMatrix, n))
            {
                QMatrix[k][c] = 1;
                check = canSolveNQueens(k + 1, n, QMatrix);
                if(check == true)
                    return true;
                QMatrix[k][c] = 0;
            }
        }
        return false;
    }
    
    bool canPlace(int k, int c, vector<vector<int>> &arr, int n)
    {
        //check column
        for(int r = 0; r < k; ++r)
        {
            if(arr[r][c] == 1)
                return false;
        }
        
        //check major diagonal
        int tempK = k;
        int tempC = c;
        while(inBound(--tempK, --tempC, n))
        {
            // cout << endl << "tempK: " << tempK << " tempC: " << tempC;
            // cout << endl << "arr[tempK][tempC]: " << arr[tempK][tempC];
            if(arr[tempK][tempC] == 1)
                return false;
        }
        
        tempK = k;
        tempC = c;

        //check minor diagonal
        while(inBound(--tempK, ++tempC, n))
        {
            if(arr[tempK][tempC] == 1)
                return false;
        }
        
        tempK = k;
        tempC = c;
        
        //check minor diagonal
        while(inBound(++tempK, ++tempC, n))
        {
            if(arr[tempK][tempC] == 1)
                return false;
        }
        
        
        tempK = k;
        tempC = c;
        
        //check minor diagonal
        while(inBound(++tempK, --tempC, n))
        {
            if(arr[tempK][tempC] == 1)
                return false;
        }
        
        return true;
    }
    
    bool inBound(int i, int j, int n)
    {
        if((i < n && i >= 0) && (j < n && j >=0))
            return true;
        return false;
    }
    
    void initialize(vector<vector<int>> &QMatrix, int n)
    {
        vector<int> temp(n, 0);
        for(int i = 0; i < n; ++i)
            QMatrix.push_back(temp);   
    }
};
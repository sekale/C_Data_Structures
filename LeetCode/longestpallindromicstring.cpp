class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.length();
        
        if(s == "")
        {
            return s;
        }
        
        int **matrix = new int*[n];
        
        for(int i = 0; i < n; i++)
        {
            matrix[i] = new int[n];
        }
        
        initialize_matrix(matrix, n);
        
        for(int i = 0; i < n; i++)
        {
            matrix[i][i] = 1;
        }
        
        
        int curr_length = 0;
        int max_length = 0;
        int start = 0;
        int last = 0;
        
        for(int j = 1; j < n ; j++)
        {
            curr_length = j+1;
            for(int i = 0; i+j < n; i++)
            {
                if(s[i] == s[i + j] && (matrix[i+1][i + j - 1] == 1 || matrix[i+1][i + j -1] == -1))
                {
                    if(max_length < curr_length)
                    {
                        cout << endl << "i:" << i << "\t"  << "i+j :"<< i+j;
                        start = i;
                        last = i + j;
                        max_length = curr_length;
                    }
                    
                    matrix[i][i+j] = 1;
                }
                
                else
                {
                    matrix[i][i+j] = 0;
                }
               // }
            }
        }
        
        /*for(int val = start; val <= last ; val++)
        {
            cout << s[val];
        }*/
        
        //print_matrix(matrix, n);
        //cout << endl << max_length;
        return s.substr(start,(last - start + 1));
    }
    
    void print_matrix(int **matrix, int n)
    {
        cout << endl;
        for(int i = 0; i < n; i++)
        {
            for(int m = 0; m < i; m++)
                cout << "\t";
                
            for(int j = 0; j < n; j++)
            {
                if(j >= i)
                {
                    cout << "\t";
                    cout << matrix[i][j]; 
                }
            }
            cout << endl;
        }  
        
    }
    
    void initialize_matrix(int **matrix, int n)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                
                matrix[i][j] = -1;  
            }
            //cout << endl;
        }  
    }
};
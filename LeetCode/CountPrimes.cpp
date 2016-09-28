using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        
        int *nonprimesmap;
        nonprimesmap = new int[n];
        
        for(int i = 0; i < n; i++)
        {
            nonprimesmap[i] = 1;
        }
        
        nonprimesmap[2] = 1;
        nonprimesmap[3] = 1;
        int nonprimecounter = 0;
        for(int j = 2; j < n; j++)
        {
            
            if(nonprimesmap[j] == 1)
            {
                for(int counter = j + j; counter < n; counter += j)
                {
                    nonprimesmap[counter] = 0;
                }
                
            nonprimecounter++;
            
            }
        }
        
        return nonprimecounter;
        
    }
};
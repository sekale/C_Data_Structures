class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> retString;
        stack<char> keyStack;
        
        int length = digits.length();
        
        if(length == 0)
            return retString;
            
        char *result = new char[length + 1];
        memset(result, 0x00, length + 1);
        
        for(int i = length - 1; i >= 0 ; --i)
            keyStack.push(digits[i]);
            
        char **values = new char*[8];
        
        for(int i = 0; i < 8; ++i)
            values[i] = new char[4];
        
        strcpy(values[0], "abc");
        strcpy(values[1], "def");
        strcpy(values[2], "ghi");
        strcpy(values[3], "jkl");
        strcpy(values[4], "mno");
        strcpy(values[5], "pqrs");
        strcpy(values[6], "tuv");
        strcpy(values[7], "wxyz");
        
        permuteComb(values, keyStack, length, result, retString, 0);
        return retString;
    }
    
    void printString(char *result)
    {
        int i = 0;
        for(i = 0; i < strlen(result); ++i)
            cout << result[i];
        cout << ", ";
    }
    
    void permuteComb(char **values, stack<char> &keyStack, int length, char *result, vector<string> &retString, int k)
    {
        if(keyStack.empty())
        {
            retString.push_back(result);
            return;
        }
        
        int curr = keyStack.top() - '0' - 2;
        if(curr < 0)
            return;
        char stackTop = keyStack.top();
        
        for(int i = 0; i < strlen(values[curr]); ++i)
        {
            result[k] = values[curr][i];
            keyStack.pop();
            permuteComb(values, keyStack, length, result, retString, k + 1);
            keyStack.push(stackTop);
        }
    }
};
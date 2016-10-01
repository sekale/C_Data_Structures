/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> mystack;
        stack<int> tempstack;
        vector<int> traversal_list;
        TreeNode *current = root;
    
        
        while(!mystack.empty() || current != NULL)
        {
            if(current != NULL)
            {
                mystack.push(current);
                current = current -> left;
            }
            
            else
            {
                while(!mystack.empty() && mystack.top() -> right == NULL)
                {
                    tempstack.push(mystack.top() -> val);
                    mystack.pop();
                }
                
                if(!mystack.empty())
                {
                        if(!tempstack.empty() && mystack.top() -> left != NULL && tempstack.top() == mystack.top() -> left -> val)
                        {
                            current = mystack.top() -> right;
                        }
                        
                        else if(!tempstack.empty() && mystack.top() -> right != NULL &&tempstack.top() == mystack.top() -> right -> val)
                        {
                            tempstack.push(mystack.top() -> val);

                            mystack.pop();
                            current = NULL;
                        }
                        
                        else if(mystack.top() -> right != NULL)
                        {
                            current = mystack.top() ->right;
                        }
                }
            }
        }
        
        stack<int> tempstack2;
        
        while(!tempstack.empty())
        {
            tempstack2.push(tempstack.top());
            tempstack.pop();
        }
        
        while(!tempstack2.empty())
        {
            traversal_list.push_back(tempstack2.top());
            tempstack2.pop();
        }
        
        return traversal_list;
    }
};
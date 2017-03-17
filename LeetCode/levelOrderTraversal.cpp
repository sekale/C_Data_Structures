/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        queue<TreeNode *> QtNode1;
        queue<TreeNode *> QtNode2;
        vector< vector<int> > levelNodes;
        vector<int> levelValues;
        if(root == NULL)
            return levelNodes;
        int index = 0;
        QtNode1.push(root);
        while(!QtNode1.empty())
        {
            levelValues.push_back(QtNode1.front() -> val);
            
            if(QtNode1.front() -> left != NULL)
                QtNode2.push(QtNode1.front() -> left);
            if(QtNode1.front() -> right != NULL)
                QtNode2.push(QtNode1.front() -> right);
            QtNode1.pop();
            if(QtNode1.empty())
            {
                levelNodes.push_back(levelValues);
                ++index;
                while(!QtNode2.empty())
                {
                    QtNode1.push(QtNode2.front());
                    QtNode2.pop();
                }
                levelValues.erase(levelValues.begin(), levelValues.end());
            }
        }
        return levelNodes;
    }
};
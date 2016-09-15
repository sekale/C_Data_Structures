//Last node also returns a +1 hence height is reduced by 1 before sending
/*The tree node has data, left child and right child 
struct node
{
    int data;
    node* left;
    node* right;
};

*/
int height_val(node *root);

int max_val(int a, int b)
{
    return (a > b) ? a : b;   
}

int height(node * root)
{
    int ht = height_val(root);
    return (ht - 1);
}

int height_val(node *root)
{
    if(root == NULL)
        return 0;
    
    else
    {
        return max_val(height_val(root -> left), height_val(root -> right)) + 1;
    }
}
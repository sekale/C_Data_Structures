//
//  main.cpp
//  BST
//
//  Created by Siddhant Ekale on 9/11/16.
//  Copyright (c) 2016 Siddhant Ekale. All rights reserved.
//

#include <iostream>

using namespace std;
typedef struct Node
{
    int value;
    int height;
    
    struct Node *left;
    struct Node *right;
    
}TreeNode;

TreeNode *addNode(TreeNode *root, int value)
{
    if(root == NULL)
    {
        TreeNode *temp;
        temp = (TreeNode*)malloc(sizeof(TreeNode));
        temp -> value = value;
        temp -> left = NULL;
        temp -> right = NULL;
        root= temp;
    }
    
    else if(value > root -> value)
    {
        root -> right = addNode(root -> right ,value);
    }
    
    else
    {
        root -> left = addNode(root -> left ,value);
    }
    
    return root;
    
}

int main(int argc, const char * argv[])
{
    TreeNode *root = NULL;
    root = addNode(root, 5);
    root = addNode(root, 4);
    root = addNode(root, 3);
    root = addNode(root, 10);
    root = addNode(root, 2);
    
    root = addNode(root, 100);
    root = addNode(root, 98);
    root = addNode(root, 96);
    root = addNode(root, 94);
}


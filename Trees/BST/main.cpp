//
//  main.cpp
//  BST
//
//  Created by Siddhant Ekale on 9/11/16.
//  Copyright (c) 2016 Siddhant Ekale. All rights reserved.
//

#include <iostream>
#include <stdlib.h>

using namespace std;
int maxFunct(int a, int b);

typedef struct Node
{
    int value;
    int height = 0;
    int balance_factor;
    
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
        temp -> height = 0;
        root = temp;
    }
    
    else if(value > root -> value)
    {
        root -> right = addNode(root -> right ,value);
    }
    
    else
    {
        root -> left = addNode(root -> left ,value);
    }
    
    if(root -> left != NULL && root -> right != NULL){
        root -> height = maxFunct(root -> left -> height, root -> right ->height) + 1;
        root -> balance_factor = (root -> left -> height - root -> right -> height);
    }
    
    else if(root -> left != NULL){
        root -> height = root -> left -> height + 1;
        root -> balance_factor = root -> left -> height;
    }
    
    else if(root -> right != NULL){
        root -> height = root -> right -> height + 1;
        root -> balance_factor = root -> right -> height;
    }
    
    //4 conditions for balancing AVL trees
    if(root -> balance_factor > 1)              //L
    {
        if(value < root -> left -> left -> value){      //LL
            TreeNode *temp_node;
            temp_node = root -> right;
            root -> right = root -> right -> right;
            root -> right -> right = temp_node;
        }
        
        else{                                   //LR
            
        }
    }
    
    else if(root -> balance_factor < -1)         //R
    {
        if(value < root -> left -> value)       //RL
        {
        }
        
        else{                                   //RR
            
        }
    }
    
    //4 conditions for balancing AVL trees

    
    return root;
}

int HeightNode(TreeNode *root)
{
    if(root == NULL)
    {
        return 0;
    }
    
    else
    {
        return maxFunct(HeightNode(root -> left), HeightNode(root -> right)) + 1;
    }
}

int maxFunct(int a, int b)
{
    if (a > b)
        return a;
    
    else
        return b;
}

int main()
{
    TreeNode *root = NULL;
    int height_root = 0;
    root = addNode(root, 5);
    root = addNode(root, 6);
    root = addNode(root, 4);
    root = addNode(root, 3);
    root = addNode(root, 2);
    cout << "done";
    //cout << HeightNode(root);
}


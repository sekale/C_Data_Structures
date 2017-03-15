#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
}listNode;

class linkedList
{
public:
    listNode *head;

    listNode* createNode(int value)
    {
        listNode *nd = new listNode();
        nd -> data = value;
        nd -> next = NULL;
        return nd;
    }

    void addNode(int value)
    {
        listNode *nd = createNode(value);

        if(head == NULL)
            head = nd;       

        else
        {
            listNode *temp = head;
            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp -> next = nd;
        }
    }

    void printList()
    {
        listNode *temp = head;
        while(temp != NULL)
        {
            cout << temp -> data << "  ->" << "  ";
            temp = temp -> next;
        }
        cout << "NULL\n";
    }
};
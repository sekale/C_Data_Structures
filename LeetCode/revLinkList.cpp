/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nxt = NULL;
        
        while(curr != NULL)
        {
            nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }
    return prev;
    }
};
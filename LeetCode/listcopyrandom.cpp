/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        RandomListNode *newhead = new RandomListNode(0);
        RandomListNode *newheadtrav;
        RandomListNode *trav = head;
        
        unordered_map<RandomListNode *, RandomListNode *> hash_map;
        
        newheadtrav = newhead;
        
        if(head == NULL)
        {
            return NULL;
        }
        
        while(trav != NULL)
        {
            newheadtrav -> label = trav -> label;
            if(trav -> next != NULL)
                newheadtrav -> next = new RandomListNode(0);
                
            else
                newheadtrav -> next = NULL;
                
            newheadtrav -> random = NULL;
        
            hash_map[trav] = newheadtrav;
            
            newheadtrav = newheadtrav -> next;
            trav = trav -> next;
        }
        
        //RANDOM NODE INSERTION
        newheadtrav = newhead;
        trav = head;
        int i = 0;
        
        unordered_map<RandomListNode *, RandomListNode *>::const_iterator got;

        while(newheadtrav != NULL)
        {
            got = hash_map.find(trav -> random);
            if(got != hash_map.end())
                newheadtrav -> random = got -> second;
                
            newheadtrav = newheadtrav -> next;
            trav = trav -> next;
        }
        //RANDOM NODE INSERTION
        
        return newhead;
    }
};
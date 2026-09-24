/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*temp1 = headA;
        ListNode*temp2 = headB;

        if(headA == nullptr){
            return headB;
        }

        if(headB == nullptr){
            return headA;
        }

        while(temp1 != temp2)
        {
            if(temp1 == nullptr){
                temp1 = headB;
            } else{
                temp1 = temp1->next;
            }
            
            if(temp2 == nullptr){
                temp2 = headA;
            } else{
                temp2 = temp2->next;
            }
        }
        return temp1;
    }
};
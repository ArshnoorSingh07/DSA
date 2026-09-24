/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr){
            return head;
        }

        ListNode* currNode = head;
        ListNode*prevNode = nullptr;
        while(currNode != nullptr)
        {
            ListNode* nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        head = prevNode;
        return head;
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return true;
        }

        ListNode*slow = head;
        ListNode*fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverseList(slow->next);
        ListNode* first = head;
        ListNode* second = secondHalf;

        bool palindrome = true;

        while(second != nullptr){
            if(first->val != second->val){
                palindrome = false;
                break;
            }
            first = first->next;
            second = second->next;
        }

        slow->next = reverseList(secondHalf); //restore list

        return palindrome;

    }
};
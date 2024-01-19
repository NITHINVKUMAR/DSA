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
 int getlength(ListNode* head){
     ListNode* temp = head;
     int len = 0;
     while(temp!=NULL){
         temp = temp->next;
         len++;
     }
     return len;
 }
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }
        int len = getlength(head);
        if(k > len){
            return head;
        }
        ListNode* prev = NULL,*curr = head,*forward = head->next;
        int count  = 0;
        while(count<k){
            
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }
        if(forward!=NULL){
            head->next = reverseKGroup(forward,k);
        }
        return prev;
    }
};
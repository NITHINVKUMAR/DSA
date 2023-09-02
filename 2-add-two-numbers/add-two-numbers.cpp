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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* newnode=new ListNode(sum%10);
            temp->next=newnode;
            temp=temp->next;
        }
        return dummy->next;
    }
};
// class Solution {
// public:
// ListNode* reverse(ListNode* head){
//     ListNode* prev = NULL;
//     ListNode* curr = head;
//     while(curr != NULL){
//         ListNode* forward = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = forward;
//     }
//     return prev;
// }
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* head1 = reverse(l1);
        // ListNode* head2 = reverse(l2);
        // int carry = 0;
        // ListNode* anshead = NULL;
        // ListNode* anstail = NULL;
        // while(head1 != NULL && head2 != NULL){
        //     int sum = head1->val + head2->val + carry;
        //     int digit = sum % 10;
        //      carry = sum / 10;
        //     ListNode* newNode = new ListNode(digit);
        //     if(anshead == NULL){
        //         anshead = newNode;
        //         anstail = newNode;
        //     }
        //     else{
        //     anstail->next = newNode;
        //     anstail = newNode;
        //     }
        //     head1 = head1->next;
        //     head2 = head2->next;
        // }
        // while(head1 != NULL){
        //     int sum = head1->val + carry;
        //     int digit = sum % 10;
        //      carry = sum / 10;
        //     ListNode* newNode = new ListNode(digit);
        //     anstail->next = newNode;
        //     anstail = newNode;
        //     head1 = head1->next;
        // } 
        // while(head2 != NULL){
        //     int sum = head2->val + carry;
        //     int digit = sum % 10;
        //      carry = sum / 10;
        //     ListNode* newNode = new ListNode(digit);
        //     anstail->next = newNode;
        //     anstail = newNode;
        //     head2 = head2->next;
        // }
        // while(carry != 0){ 
        //     int sum = carry;
        //     int digit = sum % 10;
        //      carry = sum / 10;
        //     ListNode* newNode = new ListNode(digit);
        //     anstail->next = newNode;
        //     anstail = newNode;
        // }
        //  anshead = reverse(anshead);
        // return anshead;
//     }
// };
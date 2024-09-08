// https://leetcode.com/problems/add-two-numbers/description/


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
        ListNode* a = l1;
        ListNode* b = l2;
        ListNode* ans = NULL;
        ListNode* ret = NULL;
        int carry=0;
        while(a!=NULL || b!=NULL || carry>0){
            if(a==NULL){
                ListNode* em = new ListNode();
                a=em;
            }
            if(b==NULL){    
                ListNode* em = new ListNode();
                b=em;
            }
            cout<<a->val<<" "<<b->val<<" "<<carry<<"\n";
            int value = a->val+b->val+carry;
            carry=0;
            if(value>9){
                carry = value/10;
                value = value%10;
            }
            ListNode* temp = new ListNode();
            temp->val = value;
            if(ans==NULL){
                ans=temp;
                ret=temp;
            }
            else{
                ans->next=temp;
                ans=ans->next;
            }
            a=a->next;
            b=b->next;
        }
        return ret;
    }
};
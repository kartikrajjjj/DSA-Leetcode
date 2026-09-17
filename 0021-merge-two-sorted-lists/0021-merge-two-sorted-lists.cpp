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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp=new ListNode(1);
        ListNode* ans=temp;
        ListNode* first=list1;
        ListNode* second=list2;

        while(first!=nullptr && second!=nullptr){
            if(first->val <= second->val){
                temp->next=first;
                temp=first;
                first=first->next;
            }
            else{
                temp->next = second;
                temp=second;
                second=second->next;
            }
        }
            if(first==nullptr && second!=nullptr){
                while(second!=nullptr){
                    temp->next=second;
                    temp=second;
                    second=second->next;
                }
            }
            else if(first!=nullptr && second==nullptr){
                while(first!=nullptr){
                    temp->next=first;
                    temp=first;
                    first=first->next;
                }
            }
        return ans->next;
    }
};
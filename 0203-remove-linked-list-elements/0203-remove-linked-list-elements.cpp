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
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=NULL && head->val==val){
            head=head->next;
        }
        ListNode*a=head;
        while(a!=NULL && a->next!=NULL){
            if(a->next->val==val){
                a->next=a->next->next;
            }
            else{
                a=a->next;
            }
        }
        return head;
    }
};
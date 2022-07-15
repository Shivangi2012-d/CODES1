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
    ListNode* rotateRight(ListNode* head, int k) {
        
        
        if(head==NULL || head->next==NULL)return head;
    ListNode *tmp = head;
    int cnt = 0;
    while(tmp)tmp=tmp->next,cnt++;
    tmp=head;
    k%=cnt;
    if(k==0)return head;
    while(k--)tmp = tmp->next;
    ListNode *tmpHead = head;
    while(tmp->next!=NULL){
        tmp = tmp->next;
        head = head->next;
    }
    ListNode* newHead = head->next;
    tmp->next = tmpHead;
    head->next = NULL;
    return newHead;
            
        
        }   
    
};
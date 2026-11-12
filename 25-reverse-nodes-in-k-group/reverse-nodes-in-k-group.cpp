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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur=head,*prv=nullptr,*hedd=nullptr;
        while(cur){
            int j=0;
            ListNode*nitr=cur,*lpos,*prrv=nullptr,*lnk=cur;
            while(j<k and nitr){
                lpos=nitr;
                nitr=nitr->next;
                j++;
            }
            if(j<k) break;
            if(!hedd) hedd=lpos;
            lpos->next=nullptr;
            while(cur){
                ListNode*tmp=cur->next;
                cur->next=prrv;
                prrv=cur;
                cur=tmp;
            }
            cout<<prrv->val;
            lnk->next=nitr;
            if(prv) prv->next=prrv;
            prv=lnk;
            cur=nitr;
        }
        return hedd;

    }
};
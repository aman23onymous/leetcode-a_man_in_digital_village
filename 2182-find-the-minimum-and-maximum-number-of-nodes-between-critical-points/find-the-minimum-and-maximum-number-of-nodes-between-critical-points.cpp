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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> n;
        int s=2,b=INT_MAX;
        ListNode*ptr=head;
        while(ptr->next->next){
            if((ptr->val>ptr->next->val&&ptr->next->val<ptr->next->next->val)||(ptr->val<ptr->next->val&&ptr->next->val>ptr->next->next->val)) n.push_back(s);
            s++;
            ptr=ptr->next;
        }
        if(n.size()<2) return {-1,-1};
        for(int i=0;i<n.size()-1;i++){
            b=min(b,n[i+1]-n[i]);
        }
        return {b,n[n.size()-1]-n[0]};
    }
};
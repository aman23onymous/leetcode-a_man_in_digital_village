/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* ne=new Node(-1),*ptr=head;
        Node* ty=ne;
        while(ptr){
            Node* cp=new Node(ptr->val);
            ne->next=cp;
            ptr=ptr->next;
            ne=cp;
        }
        ne=ty;
        Node* pt2=ne->next,*h;
        ptr=head;
        while(ptr){
            h=ptr;
            ptr=ptr->next;
            h->next=pt2;
            pt2=pt2->next;
            h->next->next=ptr;
        }
        ptr=head,pt2=ne->next;
        while(pt2 and ptr){
            if(ptr and ptr->random)pt2->random=ptr->random->next;
            else pt2->random=nullptr;
            ptr=pt2->next;
            if(ptr)pt2=ptr->next;
        }
        ptr=head;
        pt2=ne->next;
        while(pt2 and pt2->next){
            ptr->next=pt2->next;
            ptr=ptr->next;
            pt2->next=pt2->next->next;
            pt2=pt2->next;
        }
        if(ptr)ptr->next=nullptr;
        return ne->next;
    }
};
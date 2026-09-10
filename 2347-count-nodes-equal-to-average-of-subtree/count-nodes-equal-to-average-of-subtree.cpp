/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<TreeNode*,int>mp;
    set<TreeNode*>st;
    pair<int,int>p(TreeNode* root){
        if(!root) return {0,0};
        auto x=p(root->left);
        auto y=p(root->right);
        mp[root]=(x.first+y.first+root->val)/(x.second+y.second+1);
        return {(x.first+y.first+root->val),(x.second+y.second+1)};
    }
    void gc(TreeNode* root,int c){
        if(!root) return ;
        if(c==root->val) {cout<<(root->val)<<c<<" ";st.insert(root);}
    }
    void cla(TreeNode* root){
        if(!root) return ;
        if(root->val==2) cout<<mp[root];
        gc(root,mp[root]);
        cla(root->left);
        cla(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        p(root);
        cla(root);
        return st.size();
    }
};
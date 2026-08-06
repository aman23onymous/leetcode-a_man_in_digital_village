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
map<TreeNode*,bool>mp;
int ret;
    int sumi(TreeNode* root){
        int su=root->val;
        cout<<root->val<<" "<<mp[root]<<"\n";

        if(root->left) su+=(sumi(root->left));
        if(root->right) su+=(sumi(root->right));
        if(mp[root])ret=max(ret,su);
        return su;
    }
    vector<int> sde(TreeNode* root){
        int tr=1,mx=root->val,mn=root->val,su=root->val;
        if(root->left){
            vector<int> anl=sde(root->left);
            if(anl[0]==0) tr=0;
            mx=max(mx,anl[1]);
            mn=min(mn,anl[2]);
            if(root->val<=anl[1]) tr=0;
            su+=anl[3];
        }
        if(root->right){
            vector<int> anr=sde(root->right);
            if(anr[0]==0) tr=0;
            mx=max(mx,anr[1]);
            mn=min(mn,anr[2]);
            if(root->val>=anr[2]) tr=0;
            su+=anr[3];
        }
        mp[root]=tr;
        if(tr) ret=max(ret,su);
        return {tr,mx,mn,su};
    }
    int maxSumBST(TreeNode* root) {
        vector<int> sd=sde(root);
        // int k=sumi(root);
        return ret;
    }
};
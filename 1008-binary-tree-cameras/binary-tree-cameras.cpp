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
    int ans=0;
    int ret(TreeNode* root){
        if(!root) return 2;
        int l=ret(root->left),r=ret(root->right);
        if(l==0 or r==0){
            ans++;
            return 1;
        }
        if(1==r or 1==l) return 2;
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        if(ret(root)==0) ans+= 1;
        return ans;
    }
};
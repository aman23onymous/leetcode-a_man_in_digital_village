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
    TreeNode* bt(vector<int>& preorder, vector<int>& inorder,int i,int k,int l,int h){
        if(l>h) return nullptr;
        TreeNode* rt=new TreeNode(preorder[i]);
        for(int j=l;j<=h;j++){
            if(preorder[i]==inorder[j]){
                rt->left=bt(preorder,inorder,i+1,i+j-l,l,j-1);
                rt->right=bt(preorder,inorder,i+j-l+1,k,j+1,h);
                break;
            }
        }
        return rt;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return bt(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};
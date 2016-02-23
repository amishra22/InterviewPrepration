/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int search(vector<int>& inorder, int s, int e, int data){
        
        for(int i=s;i<=e;i++){
            if(inorder[i] == data)
                return i;
        }
    }

    TreeNode* buildTree_helper(vector<int>& inorder, vector<int>& postorder, int iStart, int iEnd, int pStart, int pEnd){
        
        if(iStart > iEnd || pStart > pEnd)
            return NULL;
            
        TreeNode* root = new TreeNode(postorder[pEnd]);
        
        if(pStart == pEnd)
            return root;
            
        int index = search(inorder,iStart,iEnd, root->val);
            
        root->left = buildTree_helper(inorder,postorder, iStart, index-1, pStart, pStart+(index-iStart)-1);
        root->right = buildTree_helper(inorder,postorder, index+1, iEnd, pStart + (index-iStart), pEnd-1);
        
        return root;
        
        
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if(inorder.size() < 1)
            return NULL;
            
        return buildTree_helper(inorder,postorder, 0, inorder.size()-1, 0, postorder.size()-1);
        
    }
};
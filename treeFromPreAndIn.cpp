/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 // Given a tree's inorder and preorder traversal. We have to construct a tree from these
 
 
class Solution {
public:

    int search(vector<int> in, int start, int end, int val){
        int i;
        for(i=start;i<=end;i++){
            if(in[i] == val)
                return i;
        }
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder,int pStart, int pEnd, int iStart, int iEnd){
        
        //base condition .. if any of the vector's index cross each other we have to return NULL
        if(pStart > pEnd || iStart > iEnd){
            return NULL;
        }
        
        // make a new node from the preorder's start index
        TreeNode* root= new TreeNode(preorder[pStart]);
        
       if(pStart == pEnd)
            return root;
            
         //find the index in the given inorder's array.. this will forms the basis of left and right subtree   
        int index = search(inorder, iStart, iEnd, root->val);
        
        root->left = buildTreeHelper(preorder,inorder, pStart+1, pStart + (index-iStart), iStart, index-1);
        root->right = buildTreeHelper(preorder,inorder, pStart + (index-iStart) +1, pEnd, index+1, iEnd);
        
        return root;
        
    }


	// this is the main function
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int iStart = 0, iEnd=inorder.size()-1;
        int pStart = 0, pEnd=preorder.size()-1;
        
        //calling the helper function
        return buildTreeHelper(preorder, inorder, pStart, pEnd, iStart, iEnd);
        
    }
};

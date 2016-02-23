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
queue<TreeNode*> q1;
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int> > vec = {};
    	vector<int> temp;
    	TreeNode *tempNode;
    	if(root == NULL)
    	    return vec;
    	
        q1.push(root);
        //q1.push(NULL);
        while(!q1.empty()){
            //size of queue .. it gives the number of nodes at a particular level
            int n=q1.size();
            
            for(int i=0; i<n; i++){
                
                tempNode = q1.front();
                q1.pop(); 
                temp.push_back(tempNode->val);
                if(tempNode->left != NULL)
                    q1.push(tempNode->left);
                if(tempNode->right != NULL)
                    q1.push(tempNode->right);
            }
            
            vec.push_back(temp);
            temp.clear();
            
        }
        
        std::reverse(vec.begin(),vec.end());
        return vec;
        
    }
};
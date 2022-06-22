/******************************************************************************
144. Binary Tree Preorder Traversal

Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,2,3]

Example 2:
Input: root = []
Output: []
*******************************************************************************/
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
    
        vector<int> vec;
    vector<int> preorderTraversal(TreeNode* root) {
        
        preOrder(root);
        return vec;
    }
    
    void preOrder(TreeNode* root)
    {
        if(root==nullptr)
            return;
        vec.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
  
};
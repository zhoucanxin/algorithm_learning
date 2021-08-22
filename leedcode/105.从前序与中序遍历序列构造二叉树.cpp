/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lc code=start
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
private:
    unordered_map<int, int> index;
public:
    TreeNode* myBuildTree(vector<int>& preorder, vector<int>& inorder, 
                            int preorder_left, int preorder_right, int inorder_left, int inorder_right){

        if (preorder_left > preorder_right)
            return nullptr;
        
        int preorder_root = preorder_left;
        int inorder_root = index[preorder[preorder_root]];
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        int left_subtree_size = inorder_root - inorder_left;
        
        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + left_subtree_size, inorder_left, inorder_root - 1);
        root->right = myBuildTree(preorder, inorder, preorder_left + left_subtree_size + 1, preorder_right, inorder_root + 1, inorder_right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int vec_size = preorder.size();
        for (int i = 0; i < vec_size; ++i) {
            index[inorder[i]] = i;
        }

        return myBuildTree(preorder, inorder, 0, vec_size - 1, 0, vec_size - 1);
    }
};
// @lc code=end


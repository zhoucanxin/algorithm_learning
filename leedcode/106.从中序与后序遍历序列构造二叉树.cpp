/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* myBuildTree(vector<int>& inorder, vector<int>& postorder, int inorder_left, int inorder_right, int postorder_left, int postorder_right) {
        if (postorder_left > postorder_right)
            return nullptr;
        
        int postorder_root = postorder_right;
        int inorder_root = index[postorder[postorder_right]];
        TreeNode* root = new TreeNode(postorder[postorder_right]);
        int left_subtree_size = inorder_root - inorder_left;

        root->left = myBuildTree(inorder, postorder, inorder_left, inorder_root - 1, postorder_left, postorder_left + left_subtree_size - 1);
        root->right = myBuildTree(inorder, postorder, inorder_root + 1, inorder_right, postorder_left + left_subtree_size, postorder_root -1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int vec_size = inorder.size();
        for (int i = 0; i < vec_size; ++i) {
            index[inorder[i]] = i;
        }
        
        return myBuildTree(inorder, postorder, 0, vec_size - 1, 0, vec_size - 1);
    }
};
// @lc code=end


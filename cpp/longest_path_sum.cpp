/*
    Question: https://leetcode.com/problems/binary-tree-maximum-path-sum/

    Author: Akhil Bidhuri
*/

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

    int maxSum(TreeNode* root, int &mSum) {
        if (root == NULL)
            return 0;
        int l = max(0, maxSum(root->left, mSum));
        int r = max(0, maxSum(root->right, mSum));
        mSum = max(mSum, l + r + root->val);
        root->val += max(l, r);
        return root->val;
    }

    int maxPathSum(TreeNode* root) {
        int mSum = INT_MIN;
        maxSum(root, mSum);
        return mSum;
    }
};
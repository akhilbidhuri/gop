/*
 Problem : https://leetcode.com/problems/construct-string-from-binary-tree/description/?envType=daily-question&envId=2024-05-02
*/

// My solution -

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
    void tree2str_util(TreeNode* root, string &result, int level) {
        if (!root) {
            result += "()";
            return;
        }
        if (level == 0)
            result += to_string(root->val);
        else
            result += "(" + to_string(root->val);
        if (root->left || root->right) {
            tree2str_util(root->left, result, level + 1);
        }
        if(root->right) {
            tree2str_util(root->right, result, level + 1);    
        }
        if (level != 0)
            result += ")";
    }

    string tree2str(TreeNode* root) {
        string result = "";
        int level = 0;
        tree2str_util(root, result, level);
        return result;
    }
};
/*
    Problem Link - https://leetcode.com/problems/path-sum-iii/?envType=study-plan-v2&envId=leetcode-75
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
    // O(N^2) solution too much recursion
    // int c=0;
    // int pathSum(TreeNode* root, int targetSum) {
    //     if(root!=NULL) {
    //         path(root,targetSum);
    //         pathSum(root->left,targetSum);
    //         pathSum(root->right,targetSum);
    //     }
    //     return c;
    // }
    // void path(TreeNode* root,int targetSum){
    //     if(root==NULL) return;
    //     if(root->val%1000000007==targetSum%1000000007) c++;
    //     path(root->left,(targetSum-root->val)%1000000007);
    //     path(root->right,(targetSum-root->val)%1000000007);
    // }
    // O(N) solution optimized but uses more space
    int pathSum(TreeNode* root, int targetSum) {
        int c = 0;
        unordered_map<int, int> sums;
        calculateSums(root, targetSum, sums, c, 0);
        return c;
    }

    void calculateSums(TreeNode* root, int targetSum, unordered_map<int, int> &sums, int &c, int sum) {
        if (root) {
            sum = (sum + root->val)%1000000007;
            if (targetSum == sum) c++;
            if (sums[sum - targetSum] != 0) {
                c += sums[sum - targetSum];
            }
            sums[sum]++;
            calculateSums(root->left, targetSum,sums, c, sum);
            calculateSums(root->right, targetSum,sums, c, sum);
            sums[sum]--;
        }
    }
};
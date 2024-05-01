/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int n = nums.size(), start = 0, end = n-1;
        // vector<int> result(n, 0);
        // int prefix = 1, suffix = 1, zcount = 0, prev_prod = 1;
        // while(end >= start) {
        //     if (nums[end] == 0) {
        //         zcount++;
        //         if (zcount > 1)
        //             return result;
        //         prev_prod = suffix;
        //     }
        //     suffix *= nums[end];
        //     end--;
        // }
        // end++;
        // while(start < n) {
        //     suffix = nums[end] ? suffix / nums[end] : prev_prod;
        //     end++;
        //     result[start] = suffix * prefix;
        //     prefix *= nums[start];
        //     start++;
        // }
        // return result;

        // Another Approach - 


        int prefixProd = 1, n = nums.size();
        vector<int> result(n, 1);
        for (int i = 0; i < n - 1; i++) {
            result[i + 1] = prefixProd * nums[i];
            prefixProd *= nums[i];
        }
        prefixProd = 1;
        for (int i = n - 1; i > 0; i--) {
            result[i - 1] *= prefixProd * nums[i];
            prefixProd *= nums[i];
        }
        return result;
    }
};
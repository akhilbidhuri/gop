/*
    Question - https://leetcode.com/problems/continuous-subarray-sum/description/
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        unordered_map<int, int> remainders;
        remainders.insert({0, -1});
        int sum = 0;
        for (int i = 0; i< nums.size();i++) {
            sum += nums[i];
            int rem = sum % k;
            if (remainders.find(rem)!=remainders.end()) {
                if (i - remainders[rem] > 1)
                    return true;
            }
            else remainders[rem] = i;
        }
        return false;
    }
};
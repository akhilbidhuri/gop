/*
    Qustion Link - https://leetcode.com/problems/remove-k-digits/

    Solution using monotonic stack

    Author: Akhil Bidhuri
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length() <= k)   
            return "0";
        
        if (k == 0) 
            return num;

        string res;
        stack<char> monotonic_stack;
        for (char c: num) {
            while (!monotonic_stack.empty() && monotonic_stack.top() > c && k > 0) {
                monotonic_stack.pop();
                k--;
            }
            monotonic_stack.push(c);

            if(monotonic_stack.size() == 1 && c == '0')
                monotonic_stack.pop();
        }

        while (k > 0 && !monotonic_stack.empty()) {
            monotonic_stack.pop();
            k--;
        }


        while (!monotonic_stack.empty()) {
            res.push_back(monotonic_stack.top());
            monotonic_stack.pop();
        }

        reverse(res.begin(), res.end());

        return res.length() > 0 ? res : "0";
    }
};
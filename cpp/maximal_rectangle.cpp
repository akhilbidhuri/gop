/*

Leetcode - https://leetcode.com/problems/maximal-rectangle/

*/


class Solution {
public:
    int maxInRow(vector<int> &arr) {
        int max_area = INT_MIN;
        stack<int> st;
        for(int i = 0;i<arr.size() + 1;i++) {
            while(!st.empty() && (i==arr.size() || arr[st.top()]>=arr[i])){
                int height=arr[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                max_area = max(max_area, height * width);
            }
            st.push(i);
        }
        return max_area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> heights(matrix[0].size(), 0);
        int max_area = INT_MIN;
        for (int i=0;i<matrix.size();i++) {
            for  (int j = 0;j<matrix[0].size();j++) {    
                heights[j] = matrix[i][j] == '0' ? 0 : heights[j] + matrix[i][j] - '0';
            }
            int area = maxInRow(heights);
            max_area = max(max_area, area);
        }
        return max_area;
    }
};
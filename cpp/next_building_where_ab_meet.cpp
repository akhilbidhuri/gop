/*
    Question Link - https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/description/
    Solution - using segment tree
    Author: Akhil Bidhuri
*/

class Solution {
    // Segment Tree - max range
    vector<int> st;
    void build_st(vector<int> &heights, int l, int r, int i) {
        if (l == r) {
            st[i] = heights[l];
            return;
        }
        int mid = (l+r) / 2;
        build_st(heights, l, mid, i*2 + 1);
        build_st(heights, mid+1, r, i*2 + 2);
        st[i] = max(st[i*2+1], st[i*2+2]); 
    }

    /*
    args -
    mv - max building height in query greater than which we need to find building
    x: query start
    y: query end
    l: current left range of segment tree
    r: current right range of segment tree
    i: index of segement tree
    */
    int query_st(int mv, int x, int y, int l, int r, int i) {
        if (l > y || r < x) {
            return INT_MAX;
        }
        int mid = (l + r) / 2;
        if (l >=x && r <= y) {
            if (mv >= st[i])
                return INT_MAX;
            if (l == r)
                return l;
            if (st[2*i + 1] > mv)
             return query_st(mv, x, y, l, mid, 2*i+1);
            return  query_st(mv, x, y, mid + 1, r, 2*i+2);
        }
        return min(query_st(mv, x, y, l, mid, 2*i+1), query_st(mv, x, y, mid + 1, r, 2*i+2));
    }


public:
    
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> res;
        st.reserve(4 * heights.size());
        build_st(heights, 0, heights.size()-1, 0);
        for (vector<int> query: queries) {
            if (query[1] < query[0]) swap(query[0], query[1]);
            if (query[0] == query[1] || heights[query[0]] < heights[query[1]]) {
                res.push_back(query[1]);
            } else {
                int mv = max(heights[query[0]], heights[query[1]]);
                int building = query_st(mv, query[1] + 1, heights.size()-1, 0, heights.size()-1, 0);
                res.push_back(building > heights.size() ? -1 : building);
            }
        }
        return res;
    }
};
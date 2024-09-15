/*
    Question Link - https://leetcode.com/problems/group-anagrams/

    Solution using signature

    Author: Akhil Bidhuri
*/

class Solution {
public:
    string getSignature(string str) {
        vector<int> chars(26, 0);
        for (char c: str) {
            chars[c-'a']++;
        }
        string sig;
        for (int i = 0;i<chars.size();i++) {
            if (chars[i] > 0)
                sig += (char)(i+'a') + to_string(chars[i]);
        }
        return sig;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramsGroup;
        
        for (string str: strs) {
            string sig = getSignature(str);
            anagramsGroup[sig].push_back(str);
        }

        vector<vector<string>> groups;

        for (auto group: anagramsGroup) {
            groups.push_back(group.second);
        }

        return groups;

    }
};
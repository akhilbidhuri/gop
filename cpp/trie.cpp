// Example program
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class TrieNode {
    private: 
    public:
        
        bool isEnd;
        vector<TrieNode*> chars;
        
        TrieNode() {
            isEnd = false;
            chars = vector<TrieNode*>(26, NULL);
        }
};


class Trie {
    private:
        TrieNode* root;
        void getSuggRec(TrieNode* curr, vector<string> &suggestions, string currS);
    public:
        Trie() {
            root = new TrieNode();    
        }
        void addWord(string s);
        vector<string> getSuggestions(string s);        
    
};

void Trie::getSuggRec(TrieNode* curr, vector<string> &suggestions, string currS) {
    if (curr==NULL) return;
    if (curr->isEnd) suggestions.push_back(currS);
    
    for(int i =0;i<curr->chars.size();i++) {
        char c = 'a' + i;
        getSuggRec(curr->chars[i], suggestions, currS + c);    
    }
}

void Trie::addWord(string s) {
    TrieNode* curr = root;
    for(char c: s) {
        if (curr->chars[c-'a']==NULL) 
        {
             curr->chars[c-'a'] = new TrieNode();
        }
        curr = curr->chars[c-'a'];
    }
    curr->isEnd = true;
};

vector<string> Trie::getSuggestions(string s) {
    vector<string> suggestions;
    TrieNode* curr = root;
    for(char c: s) {
        if (curr->chars[c-'a'] == NULL) return suggestions;
        curr = curr->chars[c-'a'];
    }
    getSuggRec(curr, suggestions, s);
    return suggestions;
}

void printVector(vector<string> v) {
    for (auto s:v) {
        cout<<s<<' ';    
    }
    cout<<endl;
}

int main()
{
    vector<int> v;
    v = {1, 2, 3};
    for(auto i: v) {
        cout<<i<<' ';       
    }
    
    Trie t = Trie();
    t.addWord("akhil");
    t.addWord("akki");
    t.addWord("bidhuri");
    t.addWord("bidhuritech");
    
    vector<string> suggestions;
    
    suggestions = t.getSuggestions("ak");
    printVector(suggestions);
    
    suggestions = t.getSuggestions("bidhuri");
    printVector(suggestions);
    
    suggestions = t.getSuggestions("gugu");
    printVector(suggestions);
    
    return 0;
}
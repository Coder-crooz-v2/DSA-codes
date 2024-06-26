#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
    char data;
    TrieNode* children[26];
    int childcount;
    bool isTerminal;
    TrieNode(char ch) {
      this->data = ch;
      for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        childcount = 0;
        isTerminal = false;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode* root, string word) {
        if(word.length() == 0) {
            root -> isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word) {
        insertUtil(root, word);
    }
    void printSuggestions(TrieNode* curr, vector<string>& temp, string prefix) {
        if(curr -> isTerminal) {
            temp.push_back(prefix);
        }
        for (char ch = 'a'; ch < 'z'; ch++) {
            TrieNode *next = curr->children[ch-'a'];
            if (next != NULL) {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> getSuggestions(string str) {
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";
        for(int i = 0; i < str.length(); i++) {
            char lastch = str[i];
            prefix.push_back(lastch);
            TrieNode* curr = prev -> children[lastch-'a'];
            if(curr == NULL)
                break;
            vector<string> temp;
            printSuggestions(curr, temp, prefix);
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie* t = new Trie();
    for(int i = 0; i < contactList.size(); i++) {
        t -> insertWord(contactList[i]);
    }
    return t->getSuggestions(queryStr);
}
int main() {
    vector<string> contactList({"code", "coding", "codding", "cod", "colly"});
    string Str = "coding";
    vector<vector<string>> answer = phoneDirectory(contactList, Str);
    for(auto i: answer) {
        for(auto j: i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
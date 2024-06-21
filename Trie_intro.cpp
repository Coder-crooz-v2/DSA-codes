#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode(char ch) {
        data = ch;
        for(int i = 0; i <= 25; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
/**
3093. Longest Common Suffix Queries
    You are given two arrays of strings wordsContainer and wordsQuery.
    For each wordsQuery[i], you need to find a string from wordsContainer that has the longest common suffix with wordsQuery[i]. If there are two or more strings in wordsContainer that share the longest common suffix, find the string that is the smallest in length. If there are two or more such strings that have the same smallest length, find the one that occurred earlier in wordsContainer.
    Return an array of integers ans, where ans[i] is the index of the string in wordsContainer that has the longest common suffix with wordsQuery[i].
    
    Example :
    Input: wordsContainer = ["abcd","bcd","xbcd"], wordsQuery = ["cd","bcd","xyz"]
    Output: [1,1,1]
    Explanation:

    Let's look at each wordsQuery[i] separately:

    For wordsQuery[0] = "cd", strings from wordsContainer that share the longest common suffix "cd" are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
    For wordsQuery[1] = "bcd", strings from wordsContainer that share the longest common suffix "bcd" are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
    For wordsQuery[2] = "xyz", there is no string from wordsContainer that shares a common suffix. Hence the longest common suffix is "", that is shared with strings at index 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
 */

#include <bits/stdc++.h>
using namespace std;
struct TrieNode {
    unordered_map<char, TrieNode*> chars;
    int len_word;
    int best;

    TrieNode() : len_word(INT_MAX), best(-1) {}
};

class Trie {
public:
    TrieNode* root;
    vector<TrieNode*> nodes;
    Trie() {
        root = new TrieNode();
        nodes.push_back(root);
    }
    ~Trie() {
        for (auto node : nodes) 
            delete node;
    }

    void insert(int idx, const string& word) {
        TrieNode* curr = root;
        for (int i = word.length() - 1; i >= 0; --i) {
            char c = word[i];
            if (curr->chars.find(c) == curr->chars.end()) {
                TrieNode* newNode = new TrieNode();
                curr->chars[c] = newNode;
                nodes.push_back(newNode);
            }
            curr = curr->chars[c];
            
            if (curr->best == -1 || curr->len_word > (int)word.length()) {
                curr->best = idx;
                curr->len_word = (int)word.length();
            }
        }
    }

    int search(const string& word) {
        TrieNode* curr = root;
        int idx = -1;
        for (int i = word.length() - 1; i >= 0; --i) {
            char c = word[i];
            if (curr->chars.find(c) == curr->chars.end()) break;
            curr = curr->chars[c];
            idx = curr->best;
        }
        return idx;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie trie;
        int min_len_idx = 0;
        
        for (int i = 0; i < wordsContainer.size(); ++i) {
            trie.insert(i, wordsContainer[i]);
            if (wordsContainer[min_len_idx].length() > wordsContainer[i].length()) {
                min_len_idx = i;
            }
        }

        vector<int> ans;
        for (const string& word : wordsQuery) {
            int idx = trie.search(word);
            if (idx == -1) {
                ans.push_back(min_len_idx);
            } else {
                ans.push_back(idx);
            }
        }
        return ans;
    }
};
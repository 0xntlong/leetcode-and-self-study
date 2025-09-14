/**
966. Vowel Spellchecker
    Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.
    For a given query word, the spell checker handles two categories of spelling mistakes:
    Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case in the wordlist.
    Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
    Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
    Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
    Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
    Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
    Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
    Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
    In addition, the spell checker operates under the following precedence rules:

    When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
    When the query matches a word up to capitlization, you should return the first such match in the wordlist.
    When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
    If the query has no matches in the wordlist, you should return the empty string.
    Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].

    Example :

    Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
    Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
 */



#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cctype>
using namespace std;
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> lowers;
        unordered_map<string, string> devowels;
        auto devowel = [](const string& w){
            string res = w;
            for (char& c : res){
                char lower = tolower(c);
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                    c = '*';
                else
                    c = lower;
            }
            return res;
        };
        for (string& w : wordlist){
            string low = w;
            for (char& c : low)
                c = tolower(c);
            if (!lowers.count(low))
                lowers[low] = w;
            string dv = devowel(w);
            if (!devowels.count(dv)) 
                devowels[dv] = w; 
        }
        vector<string> res;
        for (string q : queries){
            if (exact.count(q)){
                res.push_back(q);
                continue;
            }
            string low = q;
            for (char& c : low)
                c = tolower(c);
            if (lowers.count(low)){
                res.push_back(lowers[low]);
                continue;
            }
            string dv = devowel(q);
            if (devowels.count(dv)){
                res.push_back(devowels[dv]);
            } else {
                res.push_back("");
            }
        }
        return res;
    }
};
/**
756. Pyramid Transition Matrix
    You are stacking blocks to form a pyramid. Each block has a color, which is represented by a single letter. Each row of blocks contains one less block than the row beneath it and is centered on top.
    To make the pyramid aesthetically pleasing, there are only specific triangular patterns that are allowed. A triangular pattern consists of a single block stacked on top of two blocks. The patterns are given as a list of three-letter strings allowed, where the first two characters of a pattern represent the left and right bottom blocks respectively, and the third character is the top block.
    For example, "ABC" represents a triangular pattern with a 'C' block stacked on top of an 'A' (left) and 'B' (right) block. Note that this is different from "BAC" where 'B' is on the left bottom and 'A' is on the right bottom.
    You start with a bottom row of blocks bottom, given as a single string, that you must use as the base of the pyramid.
    Given bottom and allowed, return true if you can build the pyramid all the way to the top such that every triangular pattern in the pyramid is in allowed, or false otherwise.

    Example :
    Input: bottom = "BCD", allowed = ["BCC","CDE","CEA","FFF"]
    Output: true
    Explanation: The allowed triangular patterns are shown on the right.
    Starting from the bottom (level 3), we can build "CE" on level 2 and then build "A" on level 1.
    There are three triangular patterns in the pyramid, which are "BCC", "CDE", and "CEA". All are allowed.
 */


#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mapping;
        for (const string& triple : allowed){
            string key = triple.substr(0, 2);
            mapping[key].push_back(triple[2]);
        }
        unordered_map<string, bool> memo;
        function<bool(const string&)> DFS = [&](const string& row) -> bool {
            auto it = memo.find(row);
            if (it != memo.end())
                return it->second;
            if (row.size() == 1)
                return memo[row] = true;
            int n = (int)row.size();
            for (int i = 0; i < n - 1; i++){
                string pair = row.substr(i, 2);
                if (mapping.find(pair) == mapping.end()){
                    return memo[row] = false;
                }
            }
            function<bool(int, string&)> buildNext = [&](int i, string& nextRow) -> bool {
                if (i == n - 1){
                    return DFS(nextRow);
                }
                string pair = row.substr(i, 2);
                auto mit = mapping.find(pair);
                if (mit == mapping.end())
                    return false;
                for (char c : mit->second){
                    nextRow.push_back(c);
                    if (buildNext(i + 1, nextRow))
                        return true;
                    nextRow.pop_back();
                }
                return false;
            };
            string nextRow;
            bool good = buildNext(0, nextRow);
            memo[row] = good;
            return good;
        };
        return DFS(bottom);
    }
};
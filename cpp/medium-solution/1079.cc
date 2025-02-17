/*
1079. Letter Tile Possibilities
    You have n  tiles, where each tile has one letter tiles[i] printed on it.
    Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.
    Example :
    Input: tiles = "AAB"
    Output: 8
    Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int countLength(int n, vector<int>& freq, int unique){
            if (n == 1)
                return unique - count(freq.begin(), freq.end(), 0);
        
            int ans = 0;
            for (int i = 0; i < unique; i++){
                if (freq[i] > 0){
                    freq[i]--;
                    ans += countLength(n - 1, freq, unique);
                    freq[i]++;
                }
            }
            return ans;
        }
        int numTilePossibilities(string tiles) {
            int letters = 0;
            vector<int> freq(26, 0);
            for (char c : tiles){
                if (++freq[c - 'A'] == 1)
                    letters++;
            }
            sort(freq.begin(), freq.end(), greater<int>());
            freq.resize(letters);
            
            int total = 0;
            for (int j = 1; j <= tiles.size(); j++){
                total += countLength(j, freq, letters);
            }
            return total;
        }
    };
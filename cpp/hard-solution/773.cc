/*
773. Sliding Puzzle
    On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
    The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
    Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

    Example :
    Input: board = [[1,2,3],[4,0,5]]
    Output: 1
    Explanation: Swap the 0 and the 5 in one move.
*/

#include <vector>
#include <queue>
#include <bitset>
using namespace std;
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        static const vector<vector<char>> adj = {
            {1, 3}, {0, 2, 4}, {1, 5}, 
            {0, 4}, {1, 3, 5}, {2, 4}
        };
        static const int shift[6] = {15, 12, 9, 6, 3, 0};
        using info = pair<int, char>;
        int target = 0123450;
        int start = 0;
        char idx0 = -1;
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 3; j++){
                int index = i * 3 + j;
                start += (board[i][j] << shift[index]);
                if (board[i][j] == 0)
                    idx0 = index;
            }
        }
        if (start == target)
            return 0;
        const int N = 0543211;
        bitset<N> viz;
        queue<info> que;
        que.emplace(start, idx0);
        for (int move = 0; !que.empty(); move++){
            int qz = que.size();
            for (int i = 0; i < qz; i++){
                auto [t , p0] = que.front();
                que.pop();
                if (t == target)
                    return move;
                for (char p : adj[p0]){
                    int s = t, B = shift[p];
                    int x = ((s >> B) & 7);
                    s += -(x << B) + (x << shift[p0]);
                    if (viz[s] == 1)
                        continue;
                    que.emplace(s, p);
                    viz[s] = 1;
                }
            }
        }
        return -1;
    }
};
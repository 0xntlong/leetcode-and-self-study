/*
3394. Check if Grid can be Cut into Sections
    You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined as follows:
    (startx, starty): The bottom-left corner of the rectangle.
    (endx, endy): The top-right corner of the rectangle.
    Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:
    Each of the three resulting sections formed by the cuts contains at least one rectangle.
    Every rectangle belongs to exactly one section.
    Return true if such cuts can be made; otherwise, return false.
    Example :
    Input: n = 5, rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]
    Output: true
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        bool check(vector<pair<int, int>> &a, int n){
            vector<pair<int, int>> temp;
            temp.push_back(a[0]);
            for (int i = 0; i < n; i++){
                if (a[i].first >= temp.back().second)
                    temp.push_back(a[i]);
                else 
                    temp.back().second = max(temp.back().second, a[i].second);
            }
            return temp.size() >= 3;
        }
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            int m = rectangles.size();
            vector<pair<int, int>> x, y;
            for (auto r : rectangles){
                x.push_back({r[0], r[2]});
                y.push_back({r[1], r[3]});
            }
            sort(begin(x), end(x));
            sort(begin(y), end(y));
            return check(x, m) || check (y, m);
        }
    };
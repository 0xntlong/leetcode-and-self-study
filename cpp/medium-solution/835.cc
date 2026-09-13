/**
835. Image Overlap
    You are given two images, img1 and img2, represented as binary, square matrices of size n x n. A binary matrix has only 0s and 1s as values.
    We translate one image however we choose by sliding all the 1 bits left, right, up, and/or down any number of units. We then place it on top of the other image. We can then calculate the overlap by counting the number of positions that have a 1 in both images.
    Note also that a translation does not include any kind of rotation. Any 1 bits that are translated outside of the matrix borders are erased.
    Return the largest possible overlap.

    Example :
    Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
    Output: 3
    Explanation: We translate img1 to right by 1 unit and down by 1 unit.
    The number of positions that have a 1 in both images is 3 (shown in red).
 */




class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int result = 0;

        for (int dx = -n + 1; dx < n; dx++) {
            for (int dy = -n + 1; dy < n; dy++) {
                int score = 0;

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        int newI = i + dx;
                        int newJ = j + dy;

                        if (0 <= newI && newI < n &&
                            0 <= newJ && newJ < n) {
                            score += img1[newI][newJ] & img2[i][j];
                        }
                    }
                }

                result = max(result, score);
            }
        }

        return result;
    }
};
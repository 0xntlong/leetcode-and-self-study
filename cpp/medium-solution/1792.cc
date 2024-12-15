/*
1792. Maximum Average Pass Ratio
    There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.
    You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.
    The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.
    Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.

    Example :
    Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
    Output: 0.78333
    Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
*/

#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double, pair<int, int>>> heap;
        for (const auto& c : classes){
            int p = c[0], t=c[1];
            double priority = ((double)(p + 1) / (t + 1)) - ((double)p / t);
            heap.push({priority, {p, t}});
        }
        for (int i = 0; i < extraStudents; i++){
            auto top = heap.top();
            heap.pop();
            int p = top.second.first;
            int t = top.second.second;
            p++;
            t++;
            double priority = ((double)(p + 1) / (t + 1)) - ((double)p / t);
            heap.push({priority, {p, t}});
        }
        double ratio = 0.0;
        while (!heap.empty()){
            auto top = heap.top();
            heap.pop();
            int p = top.second.first;
            int t = top.second.second;
            ratio += (double)p / t;
        }
        return ratio / n;
    }
};
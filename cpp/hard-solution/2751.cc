/**
2751. Robot Collisions
    There are n 1-indexed robots, each having a position on a line, health, and movement direction.
    You are given 0-indexed integer arrays positions, healths, and a string directions (directions[i] is either 'L' for left or 'R' for right). All integers in positions are unique.
    All robots start moving on the line simultaneously at the same speed in their given directions. If two robots ever share the same position while moving, they will collide.
    If two robots collide, the robot with lower health is removed from the line, and the health of the other robot decreases by one. The surviving robot continues in the same direction it was going. If both robots have the same health, they are both removed from the line.
    Your task is to determine the health of the robots that survive the collisions, in the same order that the robots were given, i.e. final health of robot 1 (if survived), final health of robot 2 (if survived), and so on. If there are no survivors, return an empty array.
    Return an array containing the health of the remaining robots (in the order they were given in the input), after no further collisions can occur.

    Note: The positions may be unsorted.
    Example :
    Input: positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
    Output: [2,17,9,15,10]
    Explanation: No collision occurs in this example, since all robots are moving in the same direction. So, the health of the robots in order from the first robot is returned, [2, 17, 9, 15, 10].
 */


#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        std::vector<int> index(n);
        for (int i = 0; i < n; i++){
            index[i] = i;
        }
        std::sort(index.begin(), index.end(), [&positions](int a, int b){
            return positions[a] < positions[b];
        });
        std::vector<int> stack;
        for (int i : index){
            if (directions[i] == 'R'){
                stack.push_back(i);
                continue;
            }
            while (!stack.empty() && healths[i] > 0){
                if (healths[stack.back()] < healths[i]){
                    healths[stack.back()] = 0;
                    stack.pop_back();
                    healths[i] -= 1;
                } else if (healths[stack.back()] > healths[i]) {
                    healths[stack.back()] -= 1;
                    healths[i] = 0;
                } else {
                    healths[stack.back()] = 0;
                    healths[i] = 0;
                    stack.pop_back();
                }
            }
        }
        std::vector<int> result;
        for (int h : healths) {
            if (h > 0) {
                result.push_back(h);
            }
        }

        return result;
    }
};
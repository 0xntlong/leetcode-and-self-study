/*
1700. Number of Students Unable to Eat Lunch
    The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.
    The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:
    If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
    Otherwise, they will leave it and go to the queue's end.
    This continues until none of the queue students want to take the top sandwich and are thus unable to eat.
    You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). Return the number of students that are unable to eat.

    Example :
    Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
    Output: 0 
    Explanation:
    - Front student leaves the top sandwich and returns to the end of the line making students = [1,0,0,1].
    - Front student leaves the top sandwich and returns to the end of the line making students = [0,0,1,1].
    - Front student takes the top sandwich and leaves the line making students = [0,1,1] and sandwiches = [1,0,1].
    - Front student leaves the top sandwich and returns to the end of the line making students = [1,1,0].
    - Front student takes the top sandwich and leaves the line making students = [1,0] and sandwiches = [0,1].
    - Front student leaves the top sandwich and returns to the end of the line making students = [0,1].
    - Front student takes the top sandwich and leaves the line making students = [1] and sandwiches = [1].
    - Front student takes the top sandwich and leaves the line making students = [] and sandwiches = [].
    Hence all students are able to eat.
*/

#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> student, sandwich;
        int Loop = 0;
        for (int i = 0; i < students.size(); i++)
            student.push(students[i]);
        for (int i = 0; i < sandwiches.size(); i++)
            sandwich.push(sandwiches[i]);
        while (true){
            if (Loop == student.size())
                break;
            if (student.front() != sandwich.front()){
                student.push(student.front());
                student.pop();
                Loop++;
            } else {
                Loop = 0;
                student.pop();
                sandwich.pop();
            }
        }
        return student.size();
    }
};
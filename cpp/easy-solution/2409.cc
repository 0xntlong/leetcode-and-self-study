/*
2409. Count Days Spent Together
    Alice and Bob are traveling to Rome for separate business meetings.
    You are given 4 strings arriveAlice, leaveAlice, arriveBob, and leaveBob. Alice will be in the city from the dates arriveAlice to leaveAlice (inclusive), while Bob will be in the city from the dates arriveBob to leaveBob (inclusive). Each will be a 5-character string in the format "MM-DD", corresponding to the month and day of the date.
    Return the total number of days that Alice and Bob are in Rome together.
    You can assume that all dates occur in the same calendar year, which is not a leap year. Note that the number of days per month can be represented as: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31].

    Example :
    Input: arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
    Output: 3
    Explanation: Alice will be in Rome from August 15 to August 18. Bob will be in Rome from August 16 to August 19. They are both in Rome together on August 16th, 17th, and 18th, so the answer is 3.
*/

#include <string>
#include <vector>
using namespace std;
class Solution {
private:
    int year[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> sumDay;
public:
    int totalDays(string str){
        int month = stoi(str.substr(0, 2)), day = stoi(str.substr(3));
        return sumDay[month - 1] + day;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        sumDay.push_back(0);
        for (int i = 0; i  < 12; i++){
            sumDay.push_back(sumDay.back() + year[i]);
        }
        int arrival = max(totalDays(arriveAlice), totalDays(arriveBob));
        int departure = min(totalDays(leaveAlice), totalDays(leaveBob));
        int countDay = departure - arrival + 1;
        return max(0, countDay);
    }
};
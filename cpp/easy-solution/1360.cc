/*
1360. Number of Days Between Two Dates
    Write a program to count the number of days between two dates.
    The two dates are given as strings, their format is YYYY-MM-DD as shown in the examples.
    
    Example :
    Input: date1 = "2019-06-29", date2 = "2019-06-30"
    Output: 1
*/

#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        return abs(date_to_int(date2) - date_to_int(date1));
    }
protected:
    int date_to_int(string s_date){
        int Y = stoi(s_date.substr(0, 4));
        int M = stoi(s_date.substr(5, 2));
        int D = stoi(s_date.substr(8, 2));
        int date = 0;
        for(int y = 1971; y < Y; y++)
            date += is_leap_year(y) ? 366 : 365;
        for(int m = 1; m < M; m++)
            date += day_in_month(m, Y);
        return date + D;
    }
    bool is_leap_year(int year){
        return (year %4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
    int day_in_month(int m, int year){
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
            return 31;
        if (m == 2) 
            return is_leap_year(year) ? 29 : 28;
        return 30;
    }
};
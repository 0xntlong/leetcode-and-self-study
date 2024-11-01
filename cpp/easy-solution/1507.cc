/*
1507. Reformat Date
    Given a date string in the form Day Month Year, where:

    Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
    Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}.
    Year is in the range [1900, 2100].
    Convert the date string to the format YYYY-MM-DD, where:

    YYYY denotes the 4 digit year.
    MM denotes the 2 digit month.
    DD denotes the 2 digit day.
    

    Example :
    Input: date = "20th Oct 2052"
    Output: "2052-10-20"
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    string reformatDate(string date) {
        vector<string> s;
        int i = 0;
        while (i < (date.length())){
            string temp = "";
            while ( i < date.length() and date[i] != ' '){
                temp.push_back(date[i]);
                i++;
            }
            if (temp.length() > 0){
                if ( s.size() == 0){
                    int req_len = temp.length() - 2;
                    string x = "";
                    for ( int i = 0; i < req_len; i++ ){
                        x.push_back(temp[i]);
                    }
                    s.push_back(x);
                }
                else if (s.size() > 0){
                    s.push_back(temp);
                }
            }
            i++;
        }
        string ans = "";
        for (int i = s.size() -1; i >= 0; i--){
            if ( i == 1){
                auto it = find(months.begin(), months.end(), s[i]);
                int idx = it - months.begin();
                string x = (to_string(idx + 1));
                if (x.length() ==  1){
                    x.push_back('0');
                    reverse(x.begin(), x.end());
                }
                ans.append(x);
            }
            else if ( i == 0){
                string x = s[i];
                if (x.length() == 1){
                    x.push_back('0');
                    reverse(x.begin(), x.end());
                }
                ans.append(x);
            }
            else {
                ans.append(s[i]);
            }
            if ( i > 0){
                ans.push_back('-');
            }
        }
        return ans;
    }
};
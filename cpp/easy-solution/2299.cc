/*
2299. Strong Password Checker II
    A password is said to be strong if it satisfies all the following criteria:
    It has at least 8 characters.
    It contains at least one lowercase letter.
    It contains at least one uppercase letter.
    It contains at least one digit.
    It contains at least one special character. The special characters are the characters in the following string: "!@#$%^&*()-+".
    It does not contain 2 of the same character in adjacent positions (i.e., "aab" violates this condition, but "aba" does not).
    Given a string password, return true if it is a strong password. Otherwise, return false.

    Example :
    Input: password = "IloveLe3tcode!"
    Output: true
    Explanation: The password meets all the requirements. Therefore, we return true.
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8)
            return false;
        bool lower = false;
        bool upper = false;
        bool digit = false;
        bool special = false;
        bool adj = false;
        vector<char> specialChar = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};
        for (int i = 0; i < password.size() - 1; i++){
            if (password[i] == password[i + 1])
                return false;
        }
        for (auto c : password){
            if (c >= 'a' && c <= 'z')
                lower = true;
            else if ( c >= 'A' && c <= 'Z')
                upper = true;
            else if ( c >= '0' && c <= '9')
                digit = true;
            else if (find(specialChar.begin(),specialChar.end(), c) != specialChar.end())
                special = true; 
        }
        return lower && upper && digit && special;
    }
};
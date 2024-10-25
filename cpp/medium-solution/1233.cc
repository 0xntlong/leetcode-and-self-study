/*
1233. Remove Sub-Folders from the Filesystem
    Given a list of folders folder, return the folders after removing all sub-folders in those folders. You may return the answer in any order.
    If a folder[i] is located within another folder[j], it is called a sub-folder of it. A sub-folder of folder[j] must start with folder[j], followed by a "/". For example, "/a/b" is a sub-folder of "/a", but "/b" is not a sub-folder of "/a/b/c".
    The format of a path is one or more concatenated strings of the form: '/' followed by one or more lowercase English letters.
    For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string and "/" are not.
    
    Example :
    Input: folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
    Output: ["/a","/c/d","/c/f"]
    Explanation: Folders "/a/b" is a subfolder of "/a" and "/c/d/e" is inside of folder "/c/d" in our filesystem.
*/


#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;
        result.push_back(folder[0]);
        for (int i = 1; i < folder.size(); i++){
            string Last_folder = result.back();
            Last_folder.push_back('/');
            if (folder[i].compare(0, Last_folder.size(), Last_folder) != 0){
                result.push_back(folder[i]);
            }
        }
        return result;
    }
};
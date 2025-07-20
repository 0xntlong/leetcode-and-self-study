/**
1948. Delete Duplicate Folders in System
    Due to a bug, there are many duplicate folders in a file system. You are given a 2D array paths, where paths[i] is an array representing an absolute path to the ith folder in the file system.
    For example, ["one", "two", "three"] represents the path "/one/two/three".
    Two folders (not necessarily on the same level) are identical if they contain the same non-empty set of identical subfolders and underlying subfolder structure. The folders do not need to be at the root level to be identical. If two or more folders are identical, then mark the folders as well as all their subfolders.
    For example, folders "/a" and "/b" in the file structure below are identical. They (as well as their subfolders) should all be marked:
    /a
    /a/x
    /a/x/y
    /a/z
    /b
    /b/x
    /b/x/y
    /b/z
    However, if the file structure also included the path "/b/w", then the folders "/a" and "/b" would not be identical. Note that "/a/x" and "/b/x" would still be considered identical even with the added folder.
    Once all the identical folders and their subfolders have been marked, the file system will delete all of them. The file system only runs the deletion once, so any folders that become identical after the initial deletion are not deleted.
    Return the 2D array ans containing the paths of the remaining folders after deleting all the marked folders. The paths may be returned in any order.

    Example 1:

    Input: paths = [["a"],["c"],["d"],["a","b"],["c","b"],["d","a"]]
    Output: [["d"],["d","a"]]
    Explanation: The file structure is as shown.
    Folders "/a" and "/c" (and their subfolders) are marked for deletion because they both contain an empty
    folder named "b".
 */



#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>

using namespace std;
class Node {
public:
    string name;
    map<string, Node*> children;
    string signature;
    Node(string name) : name(name), signature(""){}
};
class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node("");
        for (auto& path : paths){
            Node* node = root;
            for (auto& folder : path){
                if (!node -> children.count(folder)){
                    node -> children[folder] = new Node(folder);
                }
                node = node -> children[folder];
            }
        }
        unordered_map<string, int> count;
        function<string(Node*)> DFS1 = [&](Node* node) -> string{
            if (node -> children.empty())
                return "";
            vector<string> subs;
            for (auto& [name, child] : node -> children){
                string subSign = DFS1(child);
                subs.push_back(name + "(" + subSign + ")");
            }
            sort(subs.begin(), subs.end());
            node -> signature = "";
            for (auto& s : subs)
                node -> signature += s;
            count[node -> signature]++;
            return node -> signature;
        };
        DFS1(root);
        vector<vector<string>> res;
        vector<string> current;
        function<void(Node*)> DFS2 = [&](Node* node){
            if (!node -> signature.empty() && count[node -> signature] > 1)
                return;
            if (!node -> name.empty()){
                current.push_back(node -> name);
                res.push_back(current);
            }
            for (auto& [name, child] : node -> children){
                DFS2(child);
            }
            if (!node -> name.empty()){
                current.pop_back();
            }
        };
        for (auto& [name, child] : root -> children){
            DFS2(child);
        }
        return res;
    }
};
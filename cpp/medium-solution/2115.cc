/*
2115. Find All Possible Recipes from Given Supplies
    You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.
    You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.
    Return a list of all the recipes that you can create. You may return the answer in any order.
    Note that two recipes may contain each other in their ingredients.
    Example :
    Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
    Output: ["bread"]
    Explanation:
    We can create "bread" since we have the ingredients "yeast" and "flour".
*/

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies){
            const int n = recipes.size();
            unordered_set<string> supply(supplies.begin(), supplies.end());
            vector<int> degree(n, 0);
            unordered_map<string, vector<int>> adj;
            for (int i = 0; i < n; i++){
                for (const string& s : ingredients[i]){
                    if (!supply.count(s)){
                        adj[s].push_back(i);
                        degree[i]++;
                    }
                }
            }
            queue<int> que;
            for (int i = 0; i < n; i++){
                if (degree[i] == 0)
                    que.push(i);
            }
            vector<string> ans;
            while (!que.empty()){
                const int i = que.front();
                que.pop();
                auto s = recipes[i];
                ans.push_back(s);
                for (auto j : adj[s]){
                    if (--degree[j] == 0)
                        que.push(j);
                }
            }
            return ans;
        }
    };
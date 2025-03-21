"""
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
"""

from collections import defaultdict, deque
from typing import List
    
class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        n = len(recipes)
        supply = set(supplies)
        degree = [0] * n
        adj = defaultdict(list)

        for i in range(n):
            for j in ingredients[i]:
                if j not in supply:
                    adj[j].append(i)
                    degree[i] += 1
        
        que = deque()
        for i in range(n):
            if degree[i] == 0:
                que.append(i)
        ans = []
        while que:
            i = que.popleft()
            ans.append(recipes[i])
            for j in adj[recipes[i]]:
                degree[j] -= 1
                if degree[j] == 0:
                    que.append(j)

        return ans
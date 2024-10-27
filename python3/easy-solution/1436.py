"""
1436. Destination City
    You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.
    It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

    Example :
    Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
    Output: "Sao Paulo" 
    Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".
"""


from typing import List
class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        n = len(paths)
        for i in range(n):
            cityB = paths[i][1]
            find = False
            for j in range(n):
                if paths[j][0] == cityB:
                    find = True
                    break
            if not find:
                return cityB
        return ""

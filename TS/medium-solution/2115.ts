/**
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


    function findAllRecipes(recipes: string[], ingredients: string[][], supplies: string[]): string[] {
        const graph: Map<string, string[]> = new Map();
        const indegree: Map<string, number> = new Map();
        const available: Set<string> = new Set(supplies);
        const res: string[] = [];
    
    
        for (let i = 0; i < recipes.length; i++) {
            const recipe = recipes[i];
            indegree.set(recipe, ingredients[i].length);
    
            for (const ing of ingredients[i]) {
                if (!graph.has(ing)) {
                    graph.set(ing, []);
                }
                graph.get(ing)?.push(recipe); 
            }
        }
    
        const queue: string[] = [...available];
    
    
        while (queue.length > 0) {
            const item = queue.shift() as string;
            if (!graph.has(item)) continue;
    
            for (const recipe of graph.get(item)!) {
                indegree.set(recipe, indegree.get(recipe)! - 1);
                if (indegree.get(recipe) === 0) {
                    res.push(recipe);
                    queue.push(recipe);
                }
            }
        }
    
        return res;
    };
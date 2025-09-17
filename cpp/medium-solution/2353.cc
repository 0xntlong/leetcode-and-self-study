/**
2353. Design a Food Rating System
    Design a food rating system that can do the following:

    Modify the rating of a food item listed in the system.
    Return the highest-rated food item for a type of cuisine in the system.
    Implement the FoodRatings class:

    FoodRatings(String[] foods, String[] cuisines, int[] ratings) Initializes the system. The food items are described by foods, cuisines and ratings, all of which have a length of n.
    foods[i] is the name of the ith food,
    cuisines[i] is the type of cuisine of the ith food, and
    ratings[i] is the initial rating of the ith food.
    void changeRating(String food, int newRating) Changes the rating of the food item with the name food.
    String highestRated(String cuisine) Returns the name of the food item that has the highest rating for the given type of cuisine. If there is a tie, return the item with the lexicographically smaller name.
    Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, that is, either x is a prefix of y, or if i is the first position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.

    Example :
    Input
    ["FoodRatings", "highestRated", "highestRated", "changeRating", "highestRated", "changeRating", "highestRated"]
    [[["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]], ["korean"], ["japanese"], ["sushi", 16], ["japanese"], ["ramen", 16], ["japanese"]]
    Output
    [null, "kimchi", "ramen", null, "sushi", null, "ramen"]

    Explanation
    FoodRatings foodRatings = new FoodRatings(["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]);
    foodRatings.highestRated("korean"); // return "kimchi"
                                        // "kimchi" is the highest rated korean food with a rating of 9.
    foodRatings.highestRated("japanese"); // return "ramen"
                                        // "ramen" is the highest rated japanese food with a rating of 14.
    foodRatings.changeRating("sushi", 16); // "sushi" now has a rating of 16.
    foodRatings.highestRated("japanese"); // return "sushi"
                                        // "sushi" is the highest rated japanese food with a rating of 16.
    foodRatings.changeRating("ramen", 16); // "ramen" now has a rating of 16.
    foodRatings.highestRated("japanese"); // return "ramen"
                                        // Both "sushi" and "ramen" have a rating of 16.
                                        // However, "ramen" is lexicographically smaller than "sushi".
 */



#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class FoodRatings {
    unordered_map<string, string> food_cuisines;
    unordered_map<string, int> food_ratings;
    struct Node {
        int rating;
        string food;
    };
    struct Cmp {
        bool operator()(const Node& a, const Node& b) const {
            if (a.rating == b.rating) return a.food > b.food; 
            return a.rating < b.rating;                  
        }
    };
    unordered_map<string, priority_queue<Node, vector<Node>, Cmp>> cuisines_heap;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = (int)foods.size();
        for (int i = 0; i < n; ++i) {
            const string& food = foods[i];
            const string& cuisine = cuisines[i];
            int rating = ratings[i];
            food_cuisines[food] = cuisine;
            food_ratings[food] = rating;
            cuisines_heap[cuisine].push({rating, food});
        }
    }
    
    void changeRating(string food, int newRating) {
        const string& cuisine = food_cuisines[food];
        food_ratings[food] = newRating;
        cuisines_heap[cuisine].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto& pq = cuisines_heap[cuisine];
        while (!pq.empty()) {
            const auto top = pq.top();
            if (food_ratings[top.food] == top.rating) return top.food;
            pq.pop(); 
        }
        return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
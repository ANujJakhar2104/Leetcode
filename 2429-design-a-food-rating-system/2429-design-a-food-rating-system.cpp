class FoodRatings {
private:
    unordered_map<string, int> food_rating;
    unordered_map<string, string> food_cuisine;
    unordered_map<string, set<pair<int,string>>> cuisine_best;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            food_rating[foods[i]] = ratings[i];
            food_cuisine[foods[i]] = cuisines[i];
            cuisine_best[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food_cuisine[food];
        int oldRating = food_rating[food];
        cuisine_best[cuisine].erase({-oldRating, food});
        food_rating[food] = newRating;
        cuisine_best[cuisine].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return cuisine_best[cuisine].begin()->second;
    }
};

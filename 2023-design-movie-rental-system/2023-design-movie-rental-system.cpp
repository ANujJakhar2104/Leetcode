class MovieRentingSystem {

private:
    set<tuple<int, int, int>> rented;
    unordered_map<int, set<pair<int, int>>> mov_pri_shop;
    unordered_map<int, set<pair<int, int>>> mov_shop_pri;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& it : entries) {
            int sh = it[0], mv = it[1], pr = it[2];
            mov_shop_pri[mv].insert({sh, pr});
            mov_pri_shop[mv].insert({pr, sh});
        }
    }

    vector<int> search(int movie) {
        vector<int> result;
        int count = 0;
        if (mov_pri_shop.count(movie)) {
            for (auto [prc, sh] : mov_pri_shop[movie]) {
                result.push_back(sh);
                count++;
                if (count == 5)
                    break;
            }
        }
        return result;
    }

    void rent(int shop, int movie) {
        auto it = mov_shop_pri[movie].lower_bound({shop, INT_MIN});
        if (it == mov_shop_pri[movie].end() || it->first != shop) {
            return;
        }

        int price = it->second;

        rented.insert({price, shop, movie});
        mov_pri_shop[movie].erase({price, shop});
    }

    void drop(int shop, int movie) {
        auto it = mov_shop_pri[movie].lower_bound({shop, INT_MIN});
        if (it == mov_shop_pri[movie].end() || it->first != shop){
            return;
        }
        int price = it->second;

        mov_pri_shop[movie].insert({price , shop});;
        rented.erase({price , shop , movie});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int count = 0;
        for (auto& [pr, sh, mv] : rented) {
            ans.push_back({sh, mv});
            count++;
            if (count == 5)
                break;
        }

        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
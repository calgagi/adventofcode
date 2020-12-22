/*
 * generated by github.com/calgagi/cp_gen
 * file: A.cpp
 * time: Mon Dec 21 20:44:53 2020
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

map<string, int> str_to_id;
map<int, string> id_to_str;
int cur_id = 1;

struct Food {
    vector<int> ingredients;
    vector<int> allergens;
};
vector<Food> foods;

string get_until_space(const string& a, int& i) {
    string ans;
    for (; i < (int) a.length() && a[i] != ' '; i++) {
        ans += a[i];
    }
    return ans;
}

void parse(string& s) {
    Food f;
    bool mode = false;

    for (int i = 0; i < (int) s.length(); i++) {
        if (!mode) {
            string in = get_until_space(s, i);
            if (in == "(contains") {
                mode = true;
                continue;
            }
            if (str_to_id[in] == 0) {
                str_to_id[in] = cur_id++;
                id_to_str[cur_id-1] = in;
            }
            f.ingredients.push_back(str_to_id[in]);
        }
        else {
            string al = get_until_space(s, i);
            al.pop_back();
            if (str_to_id[al] == 0) {
                str_to_id[al] = cur_id++;
                id_to_str[cur_id-1] = al;
            }
            f.allergens.push_back(str_to_id[al]);
        }
    }

    foods.push_back(f);
    return;
}

void part1() {
    // allergen -> ingredient -> count
    map<int, map<int,int>> cnt;
    // allergen -> count
    map<int, int> al_cnt;
    // ingredient -> count
    map<int, int> in_cnt;

    for (Food& f : foods) {
        for (int& in : f.ingredients) {
            in_cnt[in]++;
        }
        for (int& al : f.allergens) {
            al_cnt[al]++;
            for (int& in : f.ingredients) {
                cnt[al][in]++; 
            }
        }
    }

    map<int, bool> bad;
    // for each allergen
    for (const pair<int, map<int,int>>& p : cnt) {
        int id = p.first;
        // for each ingredient that the allergen points to
        for (const pair<int,int>& in : p.second) {
            if (al_cnt[id] <= in.second) {
                bad[in.first] = true;
            }
        }
    }

    ll ans = 0;
    for (const pair<int,int>& p : in_cnt) {
        if (bad[p.first] == false) {
            ans += p.second;
        }
    }
    
    cout << ans << endl;
    return;
}

void solve() {
    string line;
    while (getline(cin, line)) {
        parse(line);
    }

    part1();

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int num_tests = 1;
    /* cin >> num_tests; */
    for (int i = 0; i < num_tests; i++) {
        solve();
    }

    return 0;
}

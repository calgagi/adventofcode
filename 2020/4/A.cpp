/*
 * generated by github.com/calgagi/cp_gen
 * file: A.cpp
 * time: Thu Dec  3 21:01:58 2020
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

string get_item(string& s, int& i) {
    string ans = "";
    while(i < s.length() && s[i] != ':' && s[i] != ' ') {
        ans += s[i];
        i++;
    }
    return ans;
}

void solve() {
    vector<string> input;
    string in;
    while (getline(cin, in)) {
        input.push_back(in);
    }

    set<string> needed = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
    set<string> cur;
    int ans = 0;
    for (string& line : input) {
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ' ') {
                continue;
            }
            string key = get_item(line, i);
            i++;
            string val = get_item(line, i);
            cur.insert(key);
        }
        if (line == "") {
            int num = 7;
            for (string s : needed) {
                if (cur.count(s)) {
                    num--;
                }
            }
            if (!num) ans++;
            cur.clear(); 
        }
    }
    cout << ans << endl;
        

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

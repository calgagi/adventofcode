/*
 * generated by github.com/calgagi/cp_gen
 * file: A.cpp
 * time: Sat Dec  5 21:01:29 2020
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
    vector<string> in;
    string line;
    while (getline(cin, line)) {
        in.push_back(line);
    }

    int ans = 0;
    set<char> seen;
    for (string& s : in) {
        for (char& c : s) {
            seen.insert(c);
        }
        if (s == "") {
            ans += seen.size();
            seen.clear();
        }
    }
    ans += seen.size();
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
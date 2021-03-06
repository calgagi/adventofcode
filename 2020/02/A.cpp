/*
 * generated by github.com/calgagi/cp_gen
 * file: A.cpp
 * time: Tue Dec  1 20:58:44 2020
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
    string range;
    char letter, garb;
    string pass;

    int ans = 0;
    while (cin >> range) {
        cin >> letter >> garb;
        cin >> pass;
        int dash = range.find('-');
        int low = stoi(range.substr(0, dash));
        int high = stoi(range.substr(dash+1));
        int count = 0;
        for (char& c : pass) {
            if (c == letter) {
                count++;
            }
        }
        if (count >= low && count <= high) {
            ans++;
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
    // cin >> num_tests;
    for (int i = 0; i < num_tests; i++) {
        solve();
    }

    return 0;
}

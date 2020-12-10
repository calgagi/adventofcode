/*
 * generated by github.com/calgagi/cp_gen
 * file: A.cpp
 * time: Wed Dec  9 21:01:28 2020
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
    int x;
    vector<int> in;
    while (cin >> x) {
        in.push_back(x);
    }

    int n = in.size();
    sort(in.begin(), in.end());
    int jolt = 0;
    vector<int> diffs(3, 0);
    for (int& c : in) {
        int diff = c - jolt;
        if (diff >= 1) 
            diffs[diff-1]++;
        jolt = c;
    }

    cout << diffs[0] * (1+diffs[2]) << endl;

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

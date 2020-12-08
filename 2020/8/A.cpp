/*
 * generated by github.com/calgagi/cp_gen
 * file: A.cpp
 * time: Mon Dec  7 21:01:05 2020
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

// 0 = nop, 1 = acc, 2 = jmp
vector<pair<int,int>> ops;

void parse(const string& s) {
    string word = s.substr(0, 3);
    pair<int,int> op;
    if (word == "nop") {
        op.first = 0;
    }
    else if (word == "acc") {
        op.first = 1;
    }
    else if (word == "jmp") {
        op.first = 2;
    }

    string after = s.substr(4);
    if (after[0] == '+') {
        after.erase(after.begin());
    }
    op.second = stoi(after);
    ops.push_back(op);
    return;
}

void solve() {
    string line;
    vector<string> in;
    while (getline(cin, line)) {
        in.push_back(line);
    }

    for (string& l : in) {
        parse(l);
    }

    int n = ops.size();
    vector<bool> visited(n, false);
    int ip = 0, acc = 0;
    while (!visited[ip]) {
        visited[ip] = true;
        if (ops[ip].first == 0) {
            ip++;
        }
        else if (ops[ip].first == 1) {
            acc += ops[ip].second;
            ip++;
        }
        else if (ops[ip].first == 2) {
            ip += ops[ip].second;
        }
    }
        
    cout << acc << endl;

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
/*
 * generated by github.com/calgagi/cp_gen
 * file: A.cpp
 * time: Mon Dec  6 14:33:52 2021
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

namespace cp {

class parser {
public:
    string input = "";
    int idx = 0, len = 0;

    parser() {
        string line;
        while (getline(cin, line)) input += (line += '\n');
        len = input.length();
    }

    parser(string filename) {
        fstream f(filename, ios_base::in);
        string line;
        if (f.is_open()) while (getline(f, line)) input += (line += '\n');
        len = input.length();
    }

    bool empty() {
        return idx >= len;
    } 

    ll get_ll() {
        string num = "";
        if (idx < len && input[idx] == '-') num += input[idx++];
        while (idx < len && input[idx] >= '0' && input[idx] <= '9') num += input[idx++];
        return stoll(num);
    }

    char get_char() {
        return (idx < len ? input[idx++] : ' ');
    }

    void ws() {
        while (idx < len && input[idx] == ' ' || input[idx] == '\n' || input[idx] == '\t') idx++;
    }

    string get_word() {
        string word = "";
        while (idx < len && ((input[idx] >= 'a' && input[idx] <= 'z') || (input[idx] >= 'A' && input[idx] <= 'Z'))) word += input[idx++];
        return word;
    }

    string get_until(char deliminator = ' ') {
        string res = "";
        while (idx < len && input[idx] != deliminator && input[idx] != '\n') res += input[idx++];
        return res;
    }
};

}

/* ===== BEGIN USER CODE ===== */

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    cp::parser p;
    const int n = 7, days = 80;
    vector<ll> a(n, 0);
    while (!p.empty()) {
        a[p.get_ll()]++;
        p.get_char();
    }

    deque<ll> dq;
    for (int i = 0, j = 0; i < days; i++, j = (j + 1) % n) {
        dq.push_back(a[j]);
        if (dq.size() > 2) {
            a[j] += dq.front();
            dq.pop_front();
        }
    }
    ll ans = dq.front() + dq.back();
    for (int i = 0; i < n; i++) {
        ans += a[i];
    }
    cout << ans << endl;

    return 0;
}
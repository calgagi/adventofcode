/*
 * generated by github.com/calgagi/cp_gen
 * file: A.cpp
 * time: Wed Dec 13 09:24:05 2023
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

    char peek() {
        return input[idx];
    }
};

}

/* ===== BEGIN USER CODE ===== */

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    vector<vector<ll>> have;
    vector<vector<ll>> winning;

    cp::parser p;
    while (!p.empty()) {
        p.get_until(':'); p.get_char(); p.ws();
        vector<ll> w;
        while (p.peek() != '|') {
            w.push_back(p.get_ll());
            p.ws();
        }
        vector<ll> h;
        p.get_char(); p.ws();
        while (!p.empty() && p.peek() != 'C') {
            h.push_back(p.get_ll());
            p.ws();
        }
        p.ws();
        have.push_back(h);
        winning.push_back(w);
    }

    ll ans = 0;
    for (int i = 0; i < (int) have.size(); i++) {
        set<ll> seen(have[i].begin(), have[i].end());
        ll score = 1;
        bool ok = false;
        for (ll x : winning[i]) {
            if (seen.find(x) != seen.end()) {
                ok = true;
                score <<= 1;
            }
        }
        ans += (score >>= 1);
    }

    cout << ans << endl;

    return 0;
}

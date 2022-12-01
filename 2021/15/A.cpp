/*
 * generated by github.com/calgagi/cp_gen
 * file: A.cpp
 * time: Tue Dec 14 20:58:34 2021
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

template <class F>
struct _rlamb {
    F f;
    template <class... Args>
    decltype(auto) operator()(Args&&... args) const { return f(*this, forward<Args>(args)...); }
};

template <class F>
_rlamb<decay_t<F>> rlamb(F&& f) { return { forward<F>(f) }; }

}

/* ===== BEGIN USER CODE ===== */

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    cp::parser p;
    vector<vector<int>> a;

    while (!p.empty()) {
        vector<int> row;
        char x = p.get_char();
        cout << x;
        while (x != '\n') {
            row.push_back(x - '0');
            x = p.get_char();
            cout << x;
        }
        cout << endl;
        a.push_back(row);
        p.ws();
    }

    int n = a.size(), m = a[0].size();
    const vector<array<int, 2>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    const int MAX_N = 100, MAX_LEN = 300, INF = 1e9;
    vector<vector<vector<int>>> dp(MAX_N, vector<vector<int>>(MAX_N, vector<int>(MAX_LEN, INF)));
    dp[0][0][0] = 0;

    for (int k = 1; k < MAX_LEN; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (auto [di, dj] : dirs) {
                    int r = di + i, c = dj + j;
                    if (r < n && c < m && r >= 0 && c >= 0) {
                        dp[i][j][k] = min(dp[i][j][k], dp[r][c][k - 1] + a[i][j]);
                    }
                }
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < MAX_LEN; i++) {
        ans = min(ans, dp[n - 1][m - 1][i]);
    }
    cout << ans << endl;

    return 0;
}

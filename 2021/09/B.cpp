/*
 * generated by github.com/calgagi/cp_gen
 * file: A.cpp
 * time: Wed Dec  8 22:18:49 2021
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
        char x = p.get_char();
        vector<int> row;
        while (x != '\n') {
            row.push_back(x - '0');
            x = p.get_char();
        }
        a.push_back(row);
    }

    int n = a.size(), m = a[0].size();
    const vector<array<int, 2>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    vector<vector<int>> visited(n, vector<int>(m, -1));
    int cur_basin = 0;

    auto valid = [&](int i, int j) -> bool {
        return i < n && i >= 0 && j < m && j >= 0 && a[i][j] != 9;
    };

    auto dfs = cp::rlamb([&](auto&& dfs, int i, int j) -> void {
        visited[i][j] = cur_basin;
        for (auto [dr, dc] : dirs) {
            int r = i + dr, c = j + dc;
            if (valid(r, c) && a[i][j] < a[r][c]) {
                dfs(r, c);
            }
        }
        return;
    });

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == -1 && valid(i, j)) {
                dfs(i, j);
                cur_basin++;
            }
        }
    }

    vector<ll> basins(cur_basin, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] != -1) {
                basins[visited[i][j]]++;
            }
        }
    }

    sort(basins.begin(), basins.end(), greater<ll>());
    cout << basins[0] * basins[1] * basins[2] << endl;

    return 0;
}

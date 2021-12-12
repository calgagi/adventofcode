/*
 * generated by github.com/calgagi/cp_gen
 * file: A.cpp
 * time: Sat Dec 11 20:01:52 2021
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

    const int n = 10, steps = 100;
    const vector<array<int, 2>> dirs = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

    vector<vector<int>> grid(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = p.get_char() - '0';
        }
        p.ws();
    }

    auto valid = [&](int i, int j) -> bool {
        return i < n && j < n && i >= 0 && j >= 0;
    };

    vector<vector<bool>> flashed;
    int ans = 0;

    auto dfs = cp::rlamb([&](auto&& dfs, int i, int j) -> void {
        if (!valid(i, j) || flashed[i][j]) {
            return;
        }
        grid[i][j]++;
        if (grid[i][j] > 9) {
            grid[i][j] = 0;
            ans++;
            flashed[i][j] = true;
            for (auto [di, dj] : dirs) {
                if (valid(i + di, j + dj)) {
                    dfs(i + di, j + dj);
                }
            }
        }
    });


    for (int t = 0; t < steps; t++) {
        flashed.assign(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dfs(i, j);
            }
        }
    }

    cout << ans << endl;

    return 0;
}

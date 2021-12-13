/*
 * generated by github.com/calgagi/cp_gen
 * file: A.cpp
 * time: Sat Dec 11 20:59:33 2021
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
    unordered_map<string, vector<string>> graph;
    while (!p.empty()) {
        string from = p.get_until('-');
        p.get_char();
        string to = p.get_until();
        graph[from].push_back(to);
        graph[to].push_back(from);
        p.ws();
    }

    unordered_map<string, bool> visited;
    ll ans = cp::rlamb([&](auto&& dfs, string cur) -> ll {
        if (cur == "end") {
            return 1;
        }
        else if (visited[cur] == true && !isupper(cur[0])) {
            return 0;
        }
        visited[cur] = true;
        ll res = 0;
        for (string& to : graph[cur]) {
            res += dfs(to);
        }
        visited[cur] = false;
        return res;
    })("start");

    cout << ans << endl;

    return 0;
}
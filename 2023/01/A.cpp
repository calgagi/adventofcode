/*
 * generated by github.com/calgagi/cp_gen
 * file: A.cpp
 * time: Fri Dec  1 11:05:13 2023
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
    int ans = 0;
    while (!p.empty()) {
        string s = p.get_until();
        p.ws();
        int first = -1, last = -1;
        for (char c : s) {
            if (c <= '9' && c >= '0') {
                if (first == -1) {
                    first = c - '0';
                }
                last = c - '0';
            }
        }
        ans += (first * 10) + last;
    }

    cout << ans << endl;

    return 0;
}

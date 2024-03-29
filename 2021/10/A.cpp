/*
 * generated by github.com/calgagi/cp_gen
 * file: A.cpp
 * time: Thu Dec  9 22:34:20 2021
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

    map<char, char> match = {
        {'(', ')'},
        {'{', '}'},
        {'[', ']'},
        {'<', '>'}
    };
    
    ll ans = 0;
    auto go = [&](string& s) {
        int n = s.length();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (match.find(s[i]) == match.end()) {
                if (st.empty() || match[st.top()] != s[i]) {
                    if (s[i] == ')') {
                        ans += 3;
                    }
                    else if (s[i] == ']') {
                        ans += 57;
                    }
                    else if (s[i] == '}') {
                        ans += 1197;
                    }
                    else {
                        ans += 25137;
                    }
                    break;
                }
                else {
                    st.pop();
                }
            }
            else {
                st.push(s[i]);
            }
        }
        return;
    };

    cp::parser p;
    while (!p.empty()) {
        string line = p.get_until();
        p.ws();
        go(line);
    }

    cout << ans << endl;

    return 0;
}

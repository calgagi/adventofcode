/*
 * generated by github.com/calgagi/cp_gen
 * file: A.cpp
 * time: Thu Dec  2 20:55:42 2021
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
    vector<string> nums;
    while (!p.empty()) {
        string s = p.get_until();
        p.ws();
        nums.push_back(s);
    }

    vector<string> nums2 = nums;
    int a = 0, b = 0;
    for (int i = 0; i < 12 && nums.size() > 1; i++) {
        vector<string> new_nums;
        int cnt = 0;
        for (string& s : nums) {
            if (s[i] == '1') {
                cnt++;
            }
        }
        char need = '1';
        if (nums.size() % 2 == 0 && nums.size() / 2 <= cnt) {
            need = '1';
        }
        else if (nums.size() % 2 == 1 && nums.size() / 2 < cnt) {
            need = '1';
        }
        else {
            need = '0';
        }
        for (string& s : nums) {
            if (s[i] == need) {
                new_nums.push_back(s);
            }
        }
        nums = new_nums;
    }
    cout << nums[0] << " " << nums.size() << endl;
    a = stoi(nums[0], 0, 2);

    nums = nums2;
    for (int i = 0; i < 12 && nums.size() > 1; i++) {
        vector<string> new_nums;
        int cnt = 0;
        for (string& s : nums) {
            if (s[i] == '0') {
                cnt++;
            }
        }
        char need = '0';
        if (nums.size() % 2 == 0 && cnt <= nums.size() / 2) {
            need = '0';
        }
        else if (nums.size() % 2 == 1 && cnt < nums.size() / 2) {
            need = '0';
        }
        else {
            need = '1';
        }
        for (string& s : nums) {
            if (s[i] == need) {
                new_nums.push_back(s);
            }
        }
        nums = new_nums;
    }
    cout << nums[0] << " " << nums.size() << endl;
    b = stoi(nums[0], 0, 2);

    cout << a * b << endl;

    return 0;
}

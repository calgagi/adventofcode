/*
 * generated by github.com/calgagi/cp_gen
 * file: A.cpp
 * time: Thu Dec 10 21:06:51 2020
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {1,1}, {-1,-1}, {0,1}, {-1, 1}, {1,-1}, {0,-1}};
vector<string> in;
int n, m;

vector<pair<int,int>> grab(int i, int j) {
    vector<pair<int,int>> ans;
    for (pair<int,int>& dir : dirs) {
        int r = i + dir.first, c = j + dir.second;
        for (; r < n && r >= 0 && c < m && c >= 0; c += dir.second, r += dir.first) {
            if (in[r][c] != '.') {
                ans.push_back(make_pair(r, c));
                break;
            }
        }
    }
    return ans;
}

void solve() {
    string line;
    while (cin >> line) {
        in.push_back(line);
    }

    n = in.size(), m = in[0].length();
    vector<vector<vector<pair<int,int>>>> see(n, vector<vector<pair<int,int>>>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            see[i][j] = grab(i, j);
        }
    }

    int changed;
    do {
        vector<string> new_in = in;
        changed = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int adj = 0;
                for (pair<int,int>& x : see[i][j]) {
                    adj += in[x.first][x.second] == '#';
                }
                if (in[i][j] == 'L' && adj == 0) {
                    new_in[i][j] = '#';
                    changed++;
                } 
                else if (in[i][j] == '#' && adj >= 5) {
                    new_in[i][j] = 'L';
                    changed++;
                }
            }
        }
        in = new_in;
    } while (changed);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += in[i][j] == '#';
        }
    }
    cout << ans << endl;
            
    
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

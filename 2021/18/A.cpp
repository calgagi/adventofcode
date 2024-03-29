/*
 * generated by github.com/calgagi/cp_gen
 * file: A.cpp
 * time: Fri Dec 17 21:10:56 2021
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

    char next() {
        return input[idx];
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

    struct node {
        ll val = -1;
        node* left = nullptr;
        node* right = nullptr;
        node* par = nullptr;
        node(node* p) : par(p) {}
        node() {}
    };

    // main node for solving
    node* head = nullptr;

    auto magnitude = cp::rlamb([&](auto&& magnitude, node* c) -> ll {
        if (c->val != -1) {
            return c->val;
        }
        return 3LL * magnitude(c->left) + 2LL * magnitude(c->right);
    });

    auto print = cp::rlamb([&](auto&& print, node* c) -> void {
        if (!c) return;
        if (c->val != -1) {
            cout << c->val;
        }
        else {
            cout << "[";
            print(c->left);
            cout << ",";
            print(c->right);
            cout << "]";
        }
    });

    auto findleft = [&](node* c) -> node* {
        node* prev = c;
        c = c->par;
        while (c && c->left == prev) {
            prev = c;
            c = c->par;
        }
        if (!c) {
            return nullptr;
        }
        c = c->left;
        while (c->right) {
            c = c->right;
        }
        return c;
    };

    auto findright = [&](node* c) -> node* {
        node* prev = c;
        c = c->par;
        while (c && c->right == prev) {
            prev = c;
            c = c->par;
        }
        if (!c) {
            return nullptr;
        }
        c = c->right;
        while (c->left) {
            c = c->left;
        }
        return c;
    };

    auto explode = [&](node* c) -> void {
        ll l = c->left->val, r = c->right->val;
        assert(l != -1 && r != -1);
        c->val = 0;
        delete c->left;
        delete c->right;
        c->left = c->right = nullptr;
        node* nl = findleft(c);
        node* nr = findright(c);
        if (nl != nullptr) {
            nl->val += l;
        }
        if (nr != nullptr) {
            nr->val += r;
        }
    };

    auto split = [&](node* c) -> void {
        assert(c->left == nullptr);
        assert(c->right == nullptr);
        c->left = new node(c), c->right = new node(c);
        c->left->val = c->val / 2, c->right->val = (c->val + 1) / 2;
        c->val = -1;
    };

    bool keep_going = true;

    auto dfsexplode = cp::rlamb([&](auto&& dfsexplode, node* c, int depth) -> void {
        if (c == nullptr) return;
        if (depth >= 4 && c->val == -1) {
            explode(c);
            keep_going = true;
            return;
        }
        dfsexplode(c->left, depth + 1);
        if (keep_going) return;
        dfsexplode(c->right, depth + 1);
        return;
    });

    auto dfssplit = cp::rlamb([&](auto&& dfssplit, node* c) -> void {
        if (c == nullptr) return;
        if (c->val >= 10) {
            split(c);
            keep_going = true;
            return;
        }
        dfssplit(c->left);
        if (keep_going) return;
        dfssplit(c->right);
        return;
    });

    auto testcase = [&]() -> void {
        do {
            keep_going = false;
            dfsexplode(head, 0);
            if (keep_going) continue;
            dfssplit(head);
        } while (keep_going);
    };

    while (!p.empty()) {
        node* head2 = new node;
        node* it = head2;
        p.get_char(); // has to be '['
        for (char c = p.next(); c != '\n'; c = p.next()) {
            if (c == '[') {
                if (it->left == nullptr) {
                    it->left = new node(it);
                    it = it->left;
                }
                else {
                    assert(it->right == nullptr);
                    it->right = new node(it);
                    it = it->right;
                }
                c = p.get_char();
            }
            else if (c == ']') {
                it = it->par;
                c = p.get_char();
            }
            else if (c == ',') {
                assert(it->left != nullptr);
                c = p.get_char();
                continue;
            }
            else {
                if (it->left == nullptr) {
                    it->left = new node(it);
                    it->left->val = p.get_ll();
                }
                else {
                    assert(it->right == nullptr);
                    it->right = new node(it);
                    it->right->val = p.get_ll();
                }
            }
        }
        p.ws();
        if (head == nullptr) {
            head = head2;
            testcase();
            print(head);
            cout << endl;
        }
        else {
            node* new_left = head;
            head = new node;
            head->left = new_left;
            head->right = head2;
            head2->par = new_left->par = head;
            cout << endl << "=====" << endl;
            print(head);
            cout << endl << endl;
            testcase();
            print(head);
            cout << endl;
        }
    }

    cout << magnitude(head) << endl;

    return 0;
}

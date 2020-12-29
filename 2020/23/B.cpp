/*
 * generated by github.com/calgagi/cp_gen
 * file: A.cpp
 * time: Tue Dec 22 22:30:14 2020
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int TURNS = 10000000, PICK = 3, NODES = 1000000;

struct Node {
    Node* next;
    int val;
    Node(int v) : val(v) {};
};

vector<Node*> val_to_node;
map<int, bool> picked_up;

Node* head = NULL;

void print_list(Node* cur) {
    for (int i = 0; i < NODES; i++) {
        cout << cur->val; 
        cur = cur->next;
    }
    cout << endl;
}

void solve() {
    string s;
    cin >> s;

    val_to_node.assign(NODES+1, NULL);

    head = new Node(s[0] - '0');
    Node* it = head;
    val_to_node[s[0] - '0'] = it;

    for (int i = 1; i < (int) s.length(); i++) {
        it->next = new Node(s[i] - '0');
        it = it->next;
        val_to_node[s[i] - '0'] = it;
    }

    // part 2
    for (int i = s.length() + 1; i <= NODES; i++) {
        it->next = new Node(i);
        it = it->next;
        val_to_node[i] = it;
    }

    // make circular
    it->next = head;
    
    Node* cur = head;
    for (int turn = 0; turn < TURNS; turn++) {
        // pickup stores PICK nodes
        Node* pickup = cur->next;
        it = cur->next;
        picked_up.clear();
        cur->next = NULL;
        for (int p = 0; p < PICK-1; p++) {
            picked_up[it->val] = true;
            it = it->next;
        }
        picked_up[it->val] = true;
        // it is at end of PICK
        cur->next = it->next;
        it->next = NULL;
        // successfully picked up PICK nodes
        for (int search = ((cur->val - 2 + NODES) % NODES) + 1; ; search = ((search - 2 + NODES) % NODES) + 1) {
            if (picked_up[search] == true) {
                continue;
            }
            int go = NODES - PICK;
            Node* it2 = val_to_node[search];
            it->next = it2->next;
            it2->next = pickup;
            break;
        } 
        cur = cur->next;
    }

    cout << (ll) val_to_node[1]->next->val * val_to_node[1]->next->next->val << endl;

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

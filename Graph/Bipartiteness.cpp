#include <bits/stdc++.h>

using namespace std;
#define  all(x) x.begin(),x.end()
#define int long long

const int N = 3e5, Inf = 1e15, Mod = 1e9 + 7;
const double Eps = 1e-9;

void abdalreem() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

}

/// if the Graph has odd Cycile it can't to be bipartite

vector<int> adj[N];
int col[N], Red = 1, Blue = 2;

bool Bipartite(int u) {
    queue<int> q;
    q.push(u);
    col[u] = Red;
    while (q.size()) {
        u = q.front();
        q.pop();
        for (auto i: adj[u]) {
            if (col[i] == 0) {
                col[i] = (col[u] == Red ? Blue : Red);
                q.push(i);
            } else if (col[i] == col[u])
                return false;
        }
    }
    return true;
}

void solve() {


}

int32_t
main() {

    abdalreem();
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        solve();
        cout << "\n";
    }

}
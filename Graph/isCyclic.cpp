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

vector<int> adj[N];
int vis[N];
int notVisited = 0, visited = 1, inProgress = 2;

bool isCyclic(int u) {
    vis[u] = inProgress;
    for (int v: adj[u]) {
        if (vis[v] == inProgress) {
            return true;
        }
        if (vis[v] == notVisited)
            if (isCyclic(v))return true;
    }
    vis[u] = visited;
    return false;
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
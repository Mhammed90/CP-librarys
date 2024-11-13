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

int n;
vector<int> adj[N];
namespace TreeDiameter {
    vector<int> dis1(N), dis2(N);

    void bfs(int src, vector<int> &dis) {
        for (int i = 0; i <= n; i++)dis[i] = Inf;
        dis[src] = 0;
        queue<int> q;
        q.push(src);
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (auto v: adj[u]) {
                if (dis[v] == Inf)
                    dis[v] = dis[u] + 1, q.push(v);
            }
        }
    }

    int calc() {
        bfs(1, dis1);
        int mx = 0, node = 0;
        for (int i = 1; i <= n; i++) {
            if (mx < dis1[i])
                mx = dis1[i], node = i;
        }
        bfs(node, dis2);
        mx = 0, node = 0;
        for (int i = 1; i <= n; i++) {
            if (mx < dis2[i])
                mx = dis2[i], node = i;
        }
///        cout << node << "\n";
///        cout << dis2[node] << "\n";
        return dis2[node];
    }

};

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
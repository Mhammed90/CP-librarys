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

struct Edge {
    int v, w;

    Edge(int V = 0, int W = 0) {
        v = V;
        w = W;
    }

    bool operator<(const Edge &other) const {
        return w > other.w;
    }
};

int n, m;
vector<Edge> adj[N];
int cost;
bool Marked[N];


void Prim() {
    cost = 0;
    priority_queue<Edge> pq;
    pq.push(Edge(1, 0));
    memset(Marked, 0, sizeof Marked);
    while (pq.size()) {
        int u = pq.top().v;
        long long curCost = pq.top().w;
        pq.pop();
        if (Marked[u])continue;
        cout << u << " ";
        cost += curCost;
        Marked[u] = 1;
        for (auto edge: adj[u]) {
            if (!Marked[edge.v]) {
                pq.push(Edge(edge.v, edge.w));
            }
        }

    }

    cout << cost << "\n";

/*

4 6
1 2 10
1 3 1
1 4 20
2 4 3
2 3 6
3 4 5

 */
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(Edge(v, w));
        adj[v].push_back(Edge(u, w));

    }
    Prim();

}

int32_t
main() {

    abdalreem();
    int tc = 1;
    //  cin >> tc;
    for (int i = 1; i <= tc; i++) {
        solve();
        cout << "\n";
    }

}
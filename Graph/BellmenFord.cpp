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
    int u, v, w;

    bool operator<(Edge const &other) {
        return w < other.w;
    }
};

int n, m, src;
vector<Edge> adj;
vector<int> path;
vector<long long> dis;

void BellmenFord() {
    // don't forget to resize the adjList with (m) number of edges
    // if done is true then there is a negative cycle
    // if dis[target] is Inf then there is no path
    /*
     copy this in solve  to resize

    dis.resize(n + 2, Inf);
    adj.resize(m);
    path.resize(n + 2, -1);

     */
    dis[src] = 0;

    bool done = true;
    for (int i = 0; i < n; i++) {
        done = false;
        for (Edge edge: adj)
            if (dis[edge.u] < Inf) {
                if (dis[edge.v] > dis[edge.u] + edge.w) {
                    dis[edge.v] = dis[edge.u] + edge.w;
                    // path[edge.v] = edge.u;
                    done = true;
                }
            }
        if (!done) {
            break;
        }
    }

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
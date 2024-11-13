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

typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
int parent[N];
int n, m, src, en;
long long ans;
vector<vector<pii>> adj;
vector<long long> dis;

int dijkstra(int Src = src, int End = en) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});
    dis[src] = 0;
    while (pq.size()) {
        int node = pq.top().second;
        long long d = pq.top().first;
        pq.pop();
        if (d != dis[node])continue;
        for (auto v: adj[node]) {
            int to = v.first;
            long long len = v.second;
            if (dis[node] + len < dis[to]) {
                dis[to] = dis[node] + len;
                pq.push({dis[to], to});
                //    parent[to] = node;
            }
        }
    }

    ans = dis[End];
    return ans;

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
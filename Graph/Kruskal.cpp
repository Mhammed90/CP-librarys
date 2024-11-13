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


struct DSU {
    vector<int> Parent, GroupSize;
    int numOfGroups;

    DSU(int n) {
        numOfGroups = n;
        Parent.resize(n + 2);
        GroupSize.resize(n + 2);
        for (int i = 0; i <= n; i++) {
            Parent[i] = i;
            GroupSize[i] = 1;
        }
    }

    int getParent(int u) {
        if (Parent[u] == u)
            return u;
        return Parent[u] = getParent(Parent[u]);
    }

    void merge(int u, int v) {
        int par1 = getParent(u);
        int par2 = getParent(v);
        if (par1 == par2) {
            return;
        }
        numOfGroups--;
        if (GroupSize[par1] > GroupSize[par2]) {
            Parent[par2] = par1;
            GroupSize[par1] += GroupSize[par2];
        } else {
            Parent[par1] = par2;
            GroupSize[par2] += GroupSize[par1];
        }
    }

    bool sameGroup(int u, int v) {
        int par1 = getParent(u);
        int par2 = getParent(v);
        return par2 == par1;
    }

    int getGroupSize(int u) {
        int par = getParent(u);
        return GroupSize[par];

    }
};


struct Edge {
    int u, v, w;

    bool operator<(Edge const &other) {
        return w < other.w;
    }
};

//find MST
void Kruskal() {
    int n, m;
    cin >> n >> m;
    vector<Edge> ans, adj(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> adj[i].u >> adj[i].v >> adj[i].w;
    }
    long long cost = 0;
    sort(all(adj));
    DSU ds(n + 2);

    for (auto i: adj) {
        if (ds.getParent(i.u) != ds.getParent(i.v)) {
            cost += i.w;
            ans.push_back(i);
            ds.merge(i.u, i.v);
        }
    }
    //   cout << cost << "\n";
    for (auto i: ans) {
        cout << i.u << " " << i.v << " " << i.w << "\n";
    }

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
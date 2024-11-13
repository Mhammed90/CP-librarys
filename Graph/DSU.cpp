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

void solve() {

    int n;
    cin >> n;

    DSU ds(n + 1);
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        ds.merge(u, i);

    }
    int ans = 0;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int pa = ds.getParent(i);
        mp[pa] = ds.GroupSize[pa];
    }
    vector<int> tmp;
    for (auto i: mp)
        tmp.push_back(i.second);
    sort(all(tmp));

    if (n == 1) {
        cout << 1;
        return;
    }
    int cur = tmp.back();
    tmp.pop_back();
    if (tmp.size())
        tmp.back() += cur;
    else tmp.push_back(cur);
    for (int i = 0; i < tmp.size(); i++) {
        ans += tmp[i] * tmp[i];
    }
    cout << ans;
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
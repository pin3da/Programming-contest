/**
*  UTP BMO
*/
using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl
#define endl '\n'

const int MN = 11010;
int visited[MN];
int prev[MN], low[MN], d[MN];
vector<vector<int> > g;
vector<pair<int, int> > bridges;

int n, m,ticks;

void dfs(int u) {
    visited[u] = true;
    d[u] = low[u] = ticks++;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (prev[u] != v) {
            if (!visited[v]) {
                prev[v] = u;
                dfs(v);
                if (d[u] < low[v]) {
                    bridges.push_back(make_pair(min(u,v), max(u,v)));
                }
                low[u] = min(low[u], low[v]);
            } else {
                low[u] = min (low[u], d[v]);
            }
        }
    }
}


void solve() {
    memset(visited, false, sizeof visited);
    memset(prev, -1, sizeof prev);
    memset(d, 0, sizeof d);

    g.assign(n, vector<int>());
    bridges.clear();


    int u,v;
    for (int i = 0; i < m; ++i) {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (n == 0) {
        cout << 0 << endl;
        return;
    }

    ticks = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }

    sort(bridges.begin(), bridges.end());
    cout<<bridges.size();
    for (int i = 0; i < bridges.size(); ++i) {
        cout<<" "<<bridges[i].first<<" "<<bridges[i].second;
    }
    cout<<endl;
}

int main() { ___

    #ifdef BMO
        freopen("c.in", "r", stdin);
    #endif

    while (cin>>n>>m and (n + m)) {
        solve();
    }

    return 0;
}


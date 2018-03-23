#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

typedef vector<vector<int>> graph;

const int MN = 100000 + 100;
int grundy[MN];

void dfs(graph &g, int node) {
    if (grundy[node] != -1) return;

    int len = g[node].size() + 2;

    vector<int> mex(len);

    for (auto to : g[node]) {
        dfs(g, to);
        if (grundy[to] < len)
            mex[grundy[to]] = true;
    }


    for (int i = 0; i < len; i++) {
        if (mex[i] == 0) {
            grundy[node] = i;
            return;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    graph g(n);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].emplace_back(v);
    }

    memset(grundy, -1, sizeof grundy);

    for (int i = 0; i < n; i++) {
        dfs(g, i);
    }

    for (int i = 0; i < n; i++) {
        cout << grundy[i] << endl;
    }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#else
    freopen("e3.in", "r", stdin);
#endif
    solve();
  return 0;
}


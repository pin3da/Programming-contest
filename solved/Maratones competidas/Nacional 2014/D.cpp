/**
*  UTP BMO
*/
using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl
#define endl '\n'

const int MN = 1010;
int n,m;
vector<int> g[MN];
int dp[MN];
int col[MN];
int in[MN];



int cycle(int node) {
    if (col[node] == 2) return 0;
    if (col[node] == 1) return 1;

    if (col[node] == 0) {
        col[node] = 1;
        for(int i=0;i<g[node].size();i++){
            int curr = g[node][i];
            if (cycle(curr))
                return 1;
        }
        col[node] = 2;
    }
    return 0;
}

int inf = MN + 10;

int solve(int node = 0) {
    if (dp[node] != -1) return dp[node];
    if (g[node].size() == 0) {
        return dp[node] = node;
    }

    int val = solve(g[node][0]);
    int ok = 1;
    for (int i = 1; i < g[node].size(); ++i ) {
        ok = ok and (val == solve(g[node][i]));
    }
    if (ok)
        return dp[node] = val;
    return dp[node] = inf;
}

int main() { ___

    #ifdef BMO
        freopen("d.in", "r", stdin);
    #endif

    while (cin>>n>>m and (n+m)) {
        for (int i = 0; i < MN; ++i) {
            g[i].clear();
            in[i] = 0;
        }
        int u, v;
        for (int i = 0; i < m; ++i) {
            cin>>u>>v;
            g[u].push_back(v);
            in[v]++;
        }


        vector<int> start;
        for (int i = 0; i < n; ++i)
            if (in[i] == 0)
                start.push_back(i);


        int possible = 1;
        for (int i = 0; i < start.size() and possible; ++i) {
            memset(col, 0, sizeof col);
            if (cycle(start[i])) {
                possible = false;
            }
            memset(dp, -1, sizeof dp);
            if (solve(start[i]) == inf) {
                possible = false;
            }
        }
        if (possible)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }

    return 0;
}



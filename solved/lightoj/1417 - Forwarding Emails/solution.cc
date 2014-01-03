using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MN 50005

int n,m;
int ticks, current_scc;
int d[MN], low[MN], scc[MN], _dp[MN];
int nodes[MN];
bool stacked[MN], visited[MN];
vector<int> g[MN], g2[MN];
stack<int> s;


void tarjan_scc(int u){
  d[u] = low[u] = ticks++;
  s.push(u);
  stacked[u] = true;
  const vector<int> &out = g[u];
  for(int i = 0; i < out.size(); ++i ){
    const int &v = out[i];
    if(d[v] == -1){
      tarjan_scc(v);
      low[u] = min(low[u], low[v]);
    }else if(stacked[v]){
      low[u] = min(low[u], low[v]);
    }
  }

  if(d[u] == low[u]){
    int v;
    do{
      v = s.top();s.pop();
      stacked[v] = false;
      scc[v] = current_scc;
    }while(u != v);
    current_scc++;
  }
}


void dfs(int node){
  if(visited[node]) return;
  visited[node] = 1;
  for(int i = 0; i< g[node].size(); ++i){
    if(scc[node] != scc[g[node][i]]) g2[node].push_back(g[node][i]);
    dfs(g[node][i]);
  }
}


int dp(int node){
  if(_dp[node] != -1) return _dp[node];
  int ans = nodes[scc[node]];
  for(int i = 0; i< g2[node].size(); ++i)
    ans = max(ans , dp(g2[node][i]) + nodes[scc[node]]);

  return _dp[node] =  ans;

}

int solve(){
  cin>>m;

  n = m;
  int u ,v ;
  for(int i = 0; i <  MN; ++i){
    g[i].clear(); d[i] = -1;stacked[i] = 0;scc[i] = -1;g2[i].clear();
  }
  ticks = current_scc = 0;

  for(int i = 0; i < m; ++i){
    cin>>u>>v;u--;v--;
    g[u].push_back(v);
  }

  for(int i = 0; i < n; ++i)
    if(scc[i] == -1)
      tarjan_scc(i);

  memset(visited, 0, sizeof visited);
  memset(_dp, -1, sizeof _dp);
  memset(nodes, 0, sizeof nodes);

  for(int i = 0; i < n; ++i) if(!visited[i]) dfs(i);
  for(int i = 0; i < n; ++i) nodes[scc[i]]++;

  int best = -1, ans = -1;
  for(int i = 0; i < n; ++i){
    int t = dp(i);
    if(t > best){
      best = t;
      ans = i;
    }
  }

  return ans + 1;
}

int main(){ ___

  int tc;cin>>tc;
  for(int i = 0; i < tc; ++i)
    printf("Case %d: %d\n",i+1,solve());

  return  0;
}

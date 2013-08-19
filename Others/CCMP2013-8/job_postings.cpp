using namespace std;
#include<bits/stdc++.h>

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef int L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

const L INF = numeric_limits<L>::max() / 4;

struct MinCostMaxFlow {
  int N;
  VVL cap, flow, cost;
  VI found;
  VL dist, pi, width;
  VPII dad;

  MinCostMaxFlow(int N) : 
    N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N, VL(N)), 
    found(N), dist(N), pi(N), width(N), dad(N) {}
  
  void AddEdge(int from, int to, L cap, L cost) {
    this->cap[from][to] = cap;
    this->cost[from][to] = cost;
  }
  
  void Relax(int s, int k, L cap, L cost, int dir) {
    L val = dist[s] + pi[s] - pi[k] + cost;
    if (cap && val < dist[k]) {
      dist[k] = val;
      dad[k] = make_pair(s, dir);
      width[k] = min(cap, width[s]);
    }
  }

  L Dijkstra(int s, int t) {
    fill(found.begin(), found.end(), false);
    fill(dist.begin(), dist.end(), INF);
    fill(width.begin(), width.end(), 0);
    dist[s] = 0;
    width[s] = INF;
    
    while (s != -1) {
      int best = -1;
      found[s] = true;
      for (int k = 0; k < N; k++) {
        if (found[k]) continue;
        Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
        Relax(s, k, flow[k][s], -cost[k][s], -1);
        if (best == -1 || dist[k] < dist[best]) best = k;
      }
      s = best;
    }

    for (int k = 0; k < N; k++)
      pi[k] = min(pi[k] + dist[k], INF);
    return width[t];
  }

  pair<L, L> GetMaxFlow(int s, int t) {
    L totflow = 0, totcost = 0;
    while (L amt = Dijkstra(s, t)) {
      totflow += amt;
      for (int x = t; x != s; x = dad[x].first) {
        if (dad[x].second == 1) {
          flow[dad[x].first][x] += amt;
          totcost += amt * cost[dad[x].first][x];
        } else {
          flow[x][dad[x].first] -= amt;
          totcost -= amt * cost[x][dad[x].first];
        }
      }
    }
    return make_pair(totflow, totcost);
  }
};

int sat[3][4] = {{4,3,2,1},{8,7,6,5},{12,11,10,9}};

int main(){

    
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
//    while(cin>>n>>m){
        if(m+n==0)break;
        MinCostMaxFlow graph(m+n+2);
                
        int t;
        for(int i = 0; i< n; ++i){
            scanf("%d",&t);
            graph.AddEdge(m+i+1, m+n+1,t,0);
        }
        
        int a,b;
        for(int i = 0; i< m; ++i){
            scanf("%d",&a);
            for(int j = 0; j< 4; ++j){
                scanf("%d",&b);
                graph.AddEdge(i+1,m+b+1,1,20-sat[a-1][j]);
            }
            graph.AddEdge(0,i+1,1,0);
        }
        
        pair<L,L> ans = graph.GetMaxFlow(0,n+m+1);
        //cout<<-ans.second<<endl;
        printf("%d\n", ans.second);
        
    
    }
    
    return 0;
}

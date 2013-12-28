using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl
#define MN 5005

struct edge{
    int to,weight;
    edge(){}
    edge(int t,int w) : to(t) , weight(w){}
    bool operator < (const edge &o) const{
        return o.weight < weight;
    }
};

vector<edge> g[MN];
int d[2][MN];

const int inf = numeric_limits<int>::max() - MN;

struct node{
  int op, v, w;
  node(){}
  node(int a, int b, int c) : op(a) , v(b), w(c) {}
  bool operator < (const node &o) const {
    if (op == o.op)
      if(w == o.w ) return v > o.v;
      return w > o.w;
    return op > o.op;
  }
};

int dijkstra(int s,int n){
    for(int i = 0; i< n; ++i)
        d[0][i] = d[1][i] = inf;

    d[0][s] = 0;
    priority_queue<node> q;
    q.push(node(0,s,0));

    while(!q.empty()){

        int nd = q.top().v;
        int dist = q.top().w;
        int op   = q.top().op;
        q.pop();

        if(nd == n-1 and op==1) return d[1][nd];

        if(dist > d[op][nd]) continue;

        //if((nd == n-1) and (op == 1)) return d[1][nd];

        for(int i = 0; i < g[nd].size(); ++i){
            int to = g[nd][i].to;
            int w_extra = g[nd][i].weight;

            if(dist + w_extra < d[0][to]){
                d[1][to] = d[0][to];
                d[0][to] = dist + w_extra;
                q.push(node(1, to, d[1][to]));
                q.push(node(0, to, d[0][to]));

            }else if(dist + w_extra > d[0][to] and dist + w_extra < d[1][to]){ //ties are not allowed
                d[1][to] = dist + w_extra;
                q.push(node(1, to, d[1][to]));
            }
        }
    }

    return inf;
}

int main(){ ___
    int tc;cin>>tc;
    for(int tid = 1; tid <= tc; ++tid){
        int n,r;cin>>n>>r;
        int u, v, w;
        for(int i = 0 ; i< n; ++i) g[i].clear();
        for(int i = 0 ; i< r; ++i){
            cin>>u>>v>>w;
            u--;v--;
            g[u].push_back(edge(v,w));
            g[v].push_back(edge(u,w));
        }
        dijkstra(0,n);
        /*for(int i = 0 ; i< n; ++i)
            cout<<d[1][i]<<" ";
        cout<<endl;*/
        printf("Case %d: %d\n",tid, d[1][n-1]);
    }

    return 0;
}

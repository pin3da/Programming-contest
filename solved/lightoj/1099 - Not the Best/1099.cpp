/**
 * INCOMPLETE
 * */

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MAXNODES 5000

struct edge{
    int to,weight;
    edge(){}
    edge(int t,int w): to(t) , weight(w){}
    bool operator < (const edge &o) const{
        return o.weight < weight;
    }
};

vector<edge> g[MAXNODES];
int d[MAXNODES]; //best path
int d2[MAXNODES]; //second best path


const int inf = numeric_limits<int>::max();

int dijkstra(int s,int n){
    for(int i = 0; i< n; ++i){
        d[i] = inf;
        d2[i] = inf;
    }

    d[s] = 0;
    d2[s] = 0;
    priority_queue<edge> q;
    q.push(edge(s,0));
    while(!q.empty()){
        int node = q.top().to;
        int dist = q.top().weight;
        q.pop();

        if(dist > d2[node]) continue;

        for(int i = 0; i< g[node].size(); ++i){
            int to = g[node][i].to;
            int w_extra = g[node][i].weight;

            if(dist + w_extra < d[to]){
                d2[to] = d[to];
                d[to] = dist + w_extra;
                q.push(edge(to,d[to]));
            }else if(dist + w_extra < d2[to]){
                d2[to] = dist + w_extra;
//                q.push(edge(to,d[to]));
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
        for(int i = 0 ; i< n; ++i)
            cout<<d2[i]<<" ";
        cout<<endl;
    }

    return 0;
}

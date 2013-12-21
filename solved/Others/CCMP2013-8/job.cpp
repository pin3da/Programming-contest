/**
* Max flow min cost using Dijkstra
*/

using namespace std;
#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define MAXNODES 250
 
typedef int L;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
 
struct Edge {
    int to;
    int cap;
    int flow;
    int cost;
    
    Edge()
    {
        flow = 0;
    }
    
    Edge(int t) {
        to = t;
        flow = 0;
    }
};
    
struct Entry{
    int node;
    int cost;
    
    Entry(int n, int c) : node(n), cost(c){}
 
    bool operator < (const Entry &o) const {
        return cost > o.cost;
    }
};    
 
 
const L INF = numeric_limits<L>::max() / 4;
 
struct MinCostMaxFlow{
 
    
    int N;
    VI found;
    VL dist,pi,width;
    VPII dad;
    vector<vector<Edge> > adjacents;
    priority_queue<Entry> pq;
 
    MinCostMaxFlow(int N){
        this->N = N;
        dad = VPII(N);
        found = VI(N,false);
        dist = VL(N,0);
        pi = VL(N,0);
        width = VL(N,0);
        adjacents = vector<vector<Edge> > (N);
        for(int i = 0; i< N; ++i){
            adjacents[i].clear();
        }
    }
 
    pair<int,int> getEdge(int from, int to){
        for(int i = 0; i < adjacents[from].size(); ++i) {
            if(adjacents[from][i].to == to){
                    return make_pair(from,i);
            }
        }
        Edge nuevo(to);
        adjacents[from].push_back(nuevo);
        return make_pair(from,adjacents[from].size()-1);
    }
 
    void AddEdge(int from, int to, int cap, int cost) {
        PII pos = getEdge(from, to);
        adjacents[pos.first][pos.second].cap = cap;
        adjacents[pos.first][pos.second].cost = cost;
    }
 
    void Relax(int s, int k, L cap, L cost, int dir) {
        L val = dist[s] + pi[s] - pi[k] + cost;
        if (cap != 0 && val < dist[k] && val >= 0) {
            dist[k] = val;
            dad[k].first = s;
            dad[k].second = dir;
            width[k] = min((L)cap,(L) width[s]);
            pq.push(Entry(k, dist[k]));
        }
    }
    
    L Dijkstra(int s, int t) {
        
        fill(all(found), false);
        fill(all(dist), INF);
        fill(all(width), 0);
        dist[s] = 0;
        width[s] = INF;
        pq = priority_queue<Entry> ();
        pq.push(Entry(s, 0));
        while (true) {
//            cout<<pq.size()<<endl;
            while(pq.size() > 0 && dist[pq.top().node] != pq.top().cost)
                pq.pop();
            if(pq.size()==0)
                break;
            s = pq.top().node; pq.pop();
            found[s] = true;
            for(int i = 0; i < adjacents[s].size();++i ){
                int k = adjacents[s][i].to;
                if (found[k]) continue;
                PII pos = getEdge(k, s);
                Relax(s, k, adjacents[s][i].cap - adjacents[s][i].flow, adjacents[s][i].cost, 1);
                Relax(s, k, adjacents[pos.first][pos.second].flow, -adjacents[pos.first][pos.second].cost, -1);
            }
        }
        for (int k = 0; k < N; k++)
            pi[k] = min(pi[k] + dist[k], INF);
        return width[t];
    }
 
    pair<L,L> GetMaxFlow(int s, int t) {
        L totflow = 0, totcost = 0;
        L amt;
        
        while ((amt = Dijkstra(s, t)) != 0) {
            totflow += amt;
            for (int x = t; x != s; x = dad[x].first) {
                if (dad[x].second == 1) {
                    PII pos = getEdge(dad[x].first,x);
                    adjacents[pos.first][pos.second].flow += (int) amt;
                    totcost += amt * adjacents[pos.first][pos.second].cost;
                } else {
                    PII pos = getEdge(x,dad[x].first);
                    adjacents[pos.first][pos.second].flow += (int) -amt;
                    totcost -= amt * adjacents[pos.first][pos.second].cost;
                }
            }
        }
        return make_pair(totflow, totcost);
    }
};
 
int sat[3][4] = {{4,3,2,1},{8,7,6,5},{12,11,10,9}};
 
int main(){
 
    
    int n,m;
    while(true){
//    while(cin>>n>>m){
		scanf("%d%d",&n,&m);
        if(m == 0 && n == 0) return 0;
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
        printf("%d\n", 20*m - ans.second);
    }
}
 

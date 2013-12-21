/**
* Acc, 0.512 
*/
using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define MAXN 101

char grid[MAXN][MAXN];
int id_pos[MAXN][MAXN];
int visited[MAXN][MAXN];

int valid(char a){
    return (a >= 'A' and a <= 'Z') or a=='m';
}

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
    
    Edge(){
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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main(){ ___
    int tc;cin>>tc;
    for(int tid = 1; tid <= tc; ++tid){
    
        int n,k,m;
        cin>>n>>k>>m;    
        vector<pair<int,int> > pos(k);
        memset(id_pos,-1,sizeof id_pos);
        
        int _id = 0;
        
        int source = _id++;
        int sink = _id++;
        
        for(int i = 0; i< n; ++i){
            for(int j = 0; j < n; ++j){
                cin>>grid[i][j];
                
                if(valid(grid[i][j]))
                    id_pos[i][j] = _id++;
                    
                if(isupper(grid[i][j]))
                    pos[grid[i][j] - 'A'] = make_pair(i,j);
            }
        }
        

        
        MinCostMaxFlow graph(k+m+2);
        
        for(int i = 0; i< n; ++i){
            for(int j = 0; j < n; ++j){
                if(isupper(grid[i][j])){
                
                    memset(visited,0,sizeof visited);
                    queue<pair<pair<int,int> ,int> > Q;
                    Q.push(make_pair(make_pair(i,j),0));
                    while(!Q.empty()){
                        int x = Q.front().first.first;
                        int y = Q.front().first.second;
                        int costo = Q.front().second;
                        Q.pop();
                        if(visited[x][y])continue;
                        visited[x][y] = true;
                        
                        if(grid[x][y]=='m'){
                            graph.AddEdge(id_pos[i][j], id_pos[x][y], 1, costo);
//                            cout<<"from "<<i<<" "<<j<<" to "<<x<<" "<<y<<" with cost: "<<costo<<endl;
                        }
                        
                        for(int kk = 0; kk  < 4; ++kk){
                            int nx = x + dx[kk];
                            int ny = y + dy[kk];
                            if(nx >= 0 and nx < n and ny >= 0 and ny < n and !visited[nx][ny] and grid[nx][ny]!='#')
                                Q.push(make_pair(make_pair(nx,ny),costo +1));
                        }
                    }
                    
                }
            }
        }
        
        int tt;
        for(int i = 0; i< k; ++i){
            cin>>tt;
            graph.AddEdge(source,id_pos[pos[i].first][pos[i].second], tt,0);
        }
        
        
        for(int i = 0; i< n; ++i)
            for(int j = 0; j< n; ++j)
                if(grid[i][j] == 'm')
                    graph.AddEdge(id_pos[i][j],sink,1,0);
         
         
        pair<int,int> f = graph.GetMaxFlow(source,sink);
        printf("Case %d: %d\n",tid, f.second);
        
        
    }

    return 0;    
}

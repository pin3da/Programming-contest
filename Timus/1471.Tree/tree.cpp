/**
* Manuel Pineda.
* ACC , 0.64
* Key_idea: 
*    compute dist to root for all nodes in the tree.
*    find the lowest common ancestor betwen u and v.
*    The distance will be : dist_to_root(u) + dist_to_root(v)  - 2*dist_to_root(LCA(u,v))
* Complexity:
*   Preprocesing O(n)
*   Each query solved in O(sqrt(n))
*/

using namespace std;
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#define MAXNODES 50010
#define D(x) cout<< #x " = "<<(x)<<endl

struct edge{
    int to,w;
    edge(){}
    edge(int T, int W): to(T), w(W){}
};

vector<edge> g[MAXNODES];
int T[MAXNODES];
int P[MAXNODES];
int L[MAXNODES];
long long dist_to_root[MAXNODES];
int n, nr;

void fill_l(){
    L[0] = 0;
    dist_to_root[0] = 0LL;
    
    vector<int> visited(n,0);
    queue<int> Q;
    Q.push(0);
    while(!Q.empty()){
        int act = Q.front();Q.pop();
        visited[act] = true;
        for(int i = 0; i< g[act].size(); ++i){
            if(visited[g[act][i].to])continue;
            T[g[act][i].to] = act;
            L[g[act][i].to] = L[act] + 1;
            dist_to_root[g[act][i].to] = dist_to_root[act] + g[act][i].w;
            Q.push(g[act][i].to);
        }
    }   
}

/**
* if node is situated in the first 
* section then P[node] = 1
* if node is situated at the beginning
* of some section then P[node] = T[node]
* if none of those two cases occurs, then 
* P[node] = P[T[node]]
**/
    
void bfs(){    
    
    vector<int> visited(n,0);
    queue<int> Q;
    Q.push(0);
    while(!Q.empty()){
        int node =  Q.front();Q.pop();
        if(visited[node])continue;
        visited[node] = true;
        
        if (L[node] < nr)
            P[node] = 1;
        else
            if(!(L[node] % nr)) // beginning of a section
                P[node] = T[node];
            else
                P[node] = P[T[node]];
                
        for(int i = 0; i< g[node].size(); ++i)
            Q.push(g[node][i].to);
    }
}

int LCA(int x, int y){
    //as long as the node in the next section of 
    //x and y is not one common ancestor
    //we get the node situated on the smaller 
    //lever closer
    while (P[x] != P[y])
      if (L[x] > L[y])
         x = P[x];
      else
         y = P[y];
    
       
    //now they are in the same section, so we trivially compute the LCA
    while (x != y)
      if (L[x] > L[y])
         x = T[x];
      else
         y = T[y];
    
    return x;
}


int main(){
    
    cin>>n;
    memset(T,-1,sizeof T);
    nr = sqrt(n);
    for(int i = 0; i< n; ++i)
        g[i].clear();

    int u,v,w;
    for(int i = 0; i< n-1; ++i){
        cin>>u>>v>>w;
        g[v].push_back(edge(u,w));
        g[u].push_back(edge(v,w));
    }

    fill_l();
    bfs();
    int queries;cin>>queries;
    
    for(int i = 0; i< queries; ++i){
        cin>>u>>v;
        cout<<(dist_to_root[u] + dist_to_root[v] - 2LL*dist_to_root[LCA(u,v)])<<endl;
    }
    

    return 0;
}



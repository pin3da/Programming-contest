using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>
#define all(x) (x).begin(), (x).end()
#define MAXNODES 1000010

typedef long long int ll;
const ll modulo  = 1e9;

// ====== union find =======
int p[MAXNODES];
ll k[MAXNODES];
int find_set(int x){return (p[x] == x) ? x : p[x] = find_set(p[x]);}
void union_set(int i,int j){p[find_set(j)] = find_set(i);}
// ====== union find =======

struct edge{
    int u,v;
    ll w;
    edge(){}
    bool operator < (const edge &o) const{
        return w > o.w;
    }
};

ll solve(vector<edge> edges,ll total){
    ll processed = 0;
    ll ans = 0 ;
    sort(all(edges));
    for(int i = 0; i< edges.size() ; ++i ){
        if(find_set(edges[i].u) != find_set(edges[i].v)){
            ans += ( (k[find_set(edges[i].u)]*k[find_set(edges[i].v)])*(total - processed) )%modulo;
            ans %= modulo;
            k[find_set(edges[i].u)] += k[find_set(edges[i].v)];
            union_set(edges[i].u,edges[i].v);
        }
        processed += edges[i].w;
    }
    
    return ans;
}


int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0; i<n; ++i){
        p[i] = i;
        k[i] = 1;
    }
    vector<edge> edges(m);
    ll total = 0 ;
    for(int i = 0;i <m;++i ){
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
        edges[i].u--;edges[i].v--;
        total += edges[i].w;
    }
    cout<<solve(edges,total)<<endl;

    return 0;	
}

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

int d, values[2005];
vector<vector<int> > G;
bool   visited[2005];

int solve( int node, int root){
    visited[node] = 1;
    
    int ans = 1;
    for(int i = 0; i < G[node].size(); i++){
        int cur = G[node][i];
        
        if(visited[cur] ) continue;
        
        if(values[cur] < values[root]) continue;
        
        if(values[cur] == values[root] && cur < root)continue;
        
        if(values[root] <= values[cur] && values[cur] - values[root] <= d){
            ans = ((ll)ans * (1 + solve(cur,root)))%mod;
        }
    }
    
    return ans;
}


int main(){
    int n,u,v;
    while( cin >>  d >> n){
        G.clear();
        G.resize(n);
        for(int i = 0; i < n; i++) cin >> values[i];
        for(int i = 0; i < n - 1; i++){
            cin >> u >> v;
            G[u - 1].push_back(v - 1);
            G[v - 1].push_back(u - 1);            
        }
        
        ll sol = 0;
        
        for(int i = 0; i < n; i++){
            memset(visited, 0, sizeof visited);
            sol = ((ll)sol + solve(i,i))%mod;           
        }       
        
        cout << sol << endl;
    }    
}

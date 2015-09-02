#include<bits/stdc++.h>
using namespace std;

bool start[100005], target[100005], vi [100005];
vector<vector<int> > G;
vector<int> sol;


void dfs(int nodo, int par, int impar, int profundidad){
    vi[nodo] = 1;
    
    int curValue = (start[nodo] + ((profundidad&1) ? impar : par)) & 1;
    if(target[nodo] != curValue){
        sol.push_back(nodo);
        if(profundidad&1)impar++;
        else par++;
    }
    
    for(int i = 0; i < G[nodo].size(); i++){
        int cur = G[nodo][i];
        if(vi[cur]) continue;
        dfs(cur,par,impar,profundidad+1);
    }
}

int main(){
    int n,u,v;
    while( cin >> n ){
        G.resize(n);
        for(int i = 0; i < n-1; i++){
            cin >> u >> v;
            u--;v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        
        for(int i = 0; i < n; i++)  cin >> start[i];
        for(int i = 0; i < n; i++)  cin >> target[i];
        memset(vi, 0, sizeof vi);    
        dfs(0,0,0,0);        
        
        cout << sol.size() << endl;
        for(int i = 0; i < sol.size(); i++)
            cout << sol[i]+1 << endl;        
    }
}

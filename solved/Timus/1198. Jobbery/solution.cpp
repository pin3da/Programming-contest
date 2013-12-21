using namespace std;
#include<bits/stdc++.h>
#define foreach(it,x) for(typeof x.begin() it = x.begin(); it != x.end(); ++it)
#define MAXN 2001

int n;

vector<int> g[MAXN];
vector<int> mio[MAXN];
int g2[MAXN]; //incoming in scc
int visited[MAXN];

int d[MAXN], low[MAXN], scc[MAXN];
bool stacked[MAXN];
stack<int> s;
int ticks, current_scc;

void tarjan(int u){
    d[u] = low[u] = ticks++;
    s.push(u);
    stacked[u] = true;
    
    const vector<int> &out = g[u];
    
    for(int k = 0 , m = out.size(); k < m; ++k){
        const int  &v = out[k];
        if(d[v] == -1){
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }else if(stacked[v]){
            low[u] = min(low[u],low[v]);
        }
    }
    
    if(d[u] == low[u]){
        int v;
        do{
            v = s.top();
            s.pop();
            stacked[v] =  false;
            scc[v] = current_scc;
        
        }while(u != v);
        current_scc++;
    }
    
}

int bfs(int s){
    int ans = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int act = q.front(); q.pop();
        if(visited[act]) continue;
        visited[act] = 1;
        ans++;
        foreach(otro,g[act]){
            if(scc[*otro]!=scc[act])g2[scc[*otro]]++;
            if(!visited[*otro])
                q.push(*otro);
        }
    }
    return ans;
}

int main(){
    scanf("%d",&n);
    int u;
    for(int i = 0; i< n; ++i){
        while(true){
            scanf("%d",&u);
            if(u==0)break;
            g[i].push_back(u-1);
        }
    }
            
    
    memset(d,-1, sizeof d);
    memset(scc,-1,sizeof scc);
    memset(g2,0,sizeof g2);
    s = stack<int>();
    memset(stacked,0,sizeof stacked);
    ticks = 0;
    current_scc = 0;
    for(int i = 0; i < n; ++i)
        if(scc[i] == -1)
            tarjan(i);
    
    memset(visited,0,sizeof visited);

    for(int i = 0; i < n; ++i){
        mio[scc[i]].push_back(i);
        if(!visited[i]) bfs(i);
    }
    
    vector<int> posibles;
    for(int i = 0; i < current_scc; ++i)
        if(g2[i]==0)posibles.push_back(i);
    
        
    if(posibles.size()==1)
        for(int i = 0; i < mio[posibles[0]].size(); ++i)
            printf("%d ",mio[posibles[0]][i]+1);    
    
    printf("0\n");
    
    return 0;
}

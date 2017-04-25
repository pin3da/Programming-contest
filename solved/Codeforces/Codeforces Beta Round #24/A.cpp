// http://codeforces.com/contest/24/problem/A

using namespace std;
#include<bits/stdc++.h>

#define foreach(it,x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define For(i,n) for(int i =0 ; i < (n); ++i)
#define D(x) cout<< #x " = " <<(x)<<endl
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MAXNODES 101


int next_int(){
    int r;cin>>r;return r;
}

struct edge{
    int to,w;
    edge(){}
    edge(int a, int b):to(a),w(b){}
};

vector<edge> g[MAXNODES];
int n;
int bfs(int start, int dir){
    queue<int> q;
    q.push(start);
    
    vector<int> visited(n,0);
    int ans = 0;
    while(!q.empty()){
        int act = q.front();
        q.pop();
        if(visited[act])continue;
        visited[act] = true;
        if(act==start){
            edge mio =  g[act][dir];
            if(mio.w < 0) ans+= mio.w;
            if(g[act][!dir].w > 0) ans -= g[act][!dir].w;
            q.push(mio.to);
        }else{
            if(!visited[g[act][0].to]){
                if(g[act][0].w < 0)ans+= g[act][0].w;
                q.push(g[act][0].to);
            }else if(!visited[g[act][1].to]){
                if(g[act][1].w < 0)ans+= g[act][1].w;
                q.push(g[act][1].to);
            }
       }
    }
    return ans;
}

int main(){ ___
    cin>>n;
    
    int u , v, w;
    For(i,n){
        cin>>u>>v>>w;
        u--;v--;
        g[u].push_back(edge(v,w));
        g[v].push_back(edge(u,-w));
    }
    
    int start = -1;
    For(i,n){
        if(g[i].size()==2){
            start = i;
            break;
       }
    }
    if(start == -1){
        cout<<0<<endl;
        return 0;
    }
    int a1 = bfs(start,0);
    int a2 = bfs(start,1);
    cout<<-max(a1,a2)<<endl;
    
    
       
    return 0;
}
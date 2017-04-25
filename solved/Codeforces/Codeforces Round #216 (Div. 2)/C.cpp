// http://codeforces.com/contest/369/problem/C

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) (x).begin(),(x).end()
#define MP 100010

struct edge{
    int to,p;
    
    edge(){}
    edge(int a,int b): to(a), p(b){}
};


typedef edge state;

int n;

int main(){ ___


    while(cin>>n){
        vector<edge> g[n+1];
        for(int i = 0; i <n -1; ++i){
            int u,v,w;
            cin>>u>>v>>w;
            w = (w==2);
            g[u].push_back(edge(v,w));
            g[v].push_back(edge(u,w));
        }
        
        queue<state >q;
        q.push(state(1,0));
        vector<int> visited(n+1,0);
        set<int> ans;
        set<int> forbbiden;
        vector<int> last(n+1,0);
        while(!q.empty()){
            state act = q.front();q.pop();
            visited[act.to]  = true;
            int level = last[act.to];
            int leaf = 1;
            for(int i = 0; i< g[act.to].size(); ++i){
                edge &e = g[act.to][i];

                if(!visited[e.to]){
                    /*if(e.p){
                        cout<<"Poisoning from "<<act.to<<" to "<<e.to<<endl;
                    }*/
                    last[e.to] = level;
                    if(e.p){
                        forbbiden.insert(level);
                        last[e.to] = e.to;
                    }
                    q.push(edge(e.to, act.p or e.p));
                    leaf = 0;
                }
            }
            
            if(leaf and act.p){
                ans.insert(level);
            }
        }
        
        vector<int> mio;
        foreach(i,ans){
            if(forbbiden.count(*i)==0)
                mio.push_back(*i);
        }
        
        cout<<mio.size()<<endl;
        for(int i = 0; i< mio.size(); ++i){
            if(i)cout<<" ";
            cout<<mio[i];
        }
        cout<<endl;
    }
    return 0;
}
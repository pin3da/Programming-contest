using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(0)
#define MAXNODES 1000
#define MP 300
#define all(x) x.begin(),x.end()

const double pi=acos(-1);

typedef vector<int> vi;
typedef vector<vi> vvi;

int N;
vi W[MP];
vi V;

void dfs(int i){
    if(!V[i]){
        V[i] = true;
          for_each(all(W[i]),dfs);
    }
}

bool conect(int s){
    V= vi(N,false);
    dfs(s);
    return find(all(V),0) == V.end();

}

int main(){
    int m,a,b,c;
    while(true){
        cin>>N>>m;
        if(N==0 && m==0)break;
        For(i,MP)
            W[i].clear();
        
        while(m--){
            cin>>a>>b>>c;
            a--;
            b--;
            W[a].push_back(b);
            if(c==2)
            W[b].push_back(a);

        }
        int ans = true;
        For(i,N)
            ans&=conect(i);
        cout<<(int)ans<<endl;

    }
    return 0;
}

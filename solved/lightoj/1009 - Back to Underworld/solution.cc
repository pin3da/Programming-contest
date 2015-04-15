
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

#define D(x) cout<< #x " = "<<x<<endl
#define endl '\n'
#define MN 20001

typedef vector<int> ady;

ady G[MN];
int col[MN];
int vis[MN];

int p1,p2;

void dfs(int s,int color){
  vis[s]=2;
  col[s]=color;
  ((color==0)?p1:p2)+=1;
  for(int i=0;i<G[s].size();++i)
    if(vis[G[s][i]]==1)
      dfs(G[s][i],(color+1)%2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int num;cin>>num;
  for(int i=1;i<=num;++i){
    int n;cin>>n;
    for(int j=0;j<MN;++j){
      G[j].clear();
      vis[j]=0;
      col[j]=3;
    }
    for(int j=0;j<n;++j){
      int u,v;cin>>u>>v;
      vis[u]=1;
      vis[v]=1;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    int ans=0;
    for(int j=0; j<MN;++j)
      if(vis[j]==1){
        p1=p2=0;
        dfs(j,0);
        ans+=max(p1,p2);
      }



    cout<<"Case "<<i<<": "<<ans<<endl;

  }
  return 0;
}

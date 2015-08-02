#include<bits/stdc++.h>
using namespace std;

vector<int> G[100000];
vector<int> GT[100000];
vector<pair<int,int> > Ftime;
vector<vector<int> > SCC;
bool visitados[100000];
int tiempo,n;


void dfs1(int n){
  visitados[n] = 1;
  tiempo++;
  for(int i=0;i<G[n].size();i++){
    int curr = G[n][i];
    if(visitados[curr])continue;
    dfs1(curr);
  }
  tiempo++;
  Ftime.push_back(make_pair(tiempo,n));
}

void dfs2(int n,vector<int> &scc){
  visitados[n] = 1;
  scc.push_back(n);
  for(int i=0;i<GT[n].size();i++){
    int curr = GT[n][i];
    if(visitados[curr])continue;
    dfs2(curr,scc);
  }
}


void scc(){
  memset(visitados,0,sizeof visitados);
  tiempo = 0;
  for(int i=0;i<2*n;i++){if(!visitados[i]) dfs1(i);}

  memset(visitados,0,sizeof visitados);
  for(int i=Ftime.size()-1;i>=0;i--){
    if(visitados[Ftime[i].second])continue;
    vector<int> _scc;
    dfs2(Ftime[i].second,_scc);
    SCC.push_back(_scc);
  }

}

bool two_sat(vector<int> &val){

  for(int i=0;i<SCC.size();i++){
    vector<bool> tmpVisitados(2*n,false);
    for(int j=0;j<SCC[i].size();j++){
      if(tmpVisitados[SCC[i][j]^1])return 0;
      if(val[SCC[i][j]] != -1) continue;
      else{
        val[SCC[i][j]] = 0;
        val[SCC[i][j]^1] = 1;
      }
      tmpVisitados[SCC[i][j]] = 1;

    }
  }

  return 1;
}

int main(){
  int m,u,v,nc=0;
  while(cin >> n >> m){
    Ftime.clear();
    SCC.clear();
    for(int i=0;i<2*n;i++){
      G[i].clear();
      GT[i].clear();
    }
    for(int i=0;i<m;i++){
      cin>>u>>v;
      int t1 = abs(u)-1;
      int t2 = abs(v)-1;
      int p = t1*2 + ((u<0)?1:0);
      int q = t2*2 + ((v<0)?1:0);
      G[p^1].push_back(q);
      G[q^1].push_back(p);
      GT[p].push_back(q^1);
      GT[q].push_back(p^1);
      //cout<<(p^1)<<" "<<q<<endl;
      //cout<<(q^1)<<" "<<p<<endl;

    }
    scc();
    vector<int> val(2*n,-1);

    // cout<<"Case "<<++nc<<": ";
    if(two_sat(val)){
      cout<<"1"<<endl;
      //vector<int> sol;
      //for(int i=0;i<2*n;i++)
        //if(i%2==0 and val[i] == 1)sol.push_back(i/2+1);
      //cout<<sol.size();
      //for(int i=0;i<sol.size();i++)cout<<" "<<sol[i];cout<<endl;
    }else{
      cout<<"0"<<endl;
    }
  }
  return 0;
}



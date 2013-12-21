using namespace std;
#include<iostream>
#include<vector>
#include<queue>
#include<map>

#include<cstring>
#define For(i,n) for(int i=0;i<(n);++i)
#define D(x) cout<<#x " = "<<(x)<<endl


typedef pair<int, int> pii;

int fun(string cad){
  int ans = 0;
  For(i,cad.size()){
    ans<<=1;
    ans+= cad[i]=='1';
  }
  return ans;
}

int main(){
  int nc,tmp;cin>>nc;
  For(i,nc){
    int n,m;cin>>n>>m;
    vector<int> movs[m];
    For(j,m){
      int k;cin>>k;
      For(p,k){
        cin>>tmp;
        movs[j].push_back(tmp);
      }
    }
        
    map<int,int> solution;
    queue<pii> Q;
    int visited[(1<<n)];
    memset(visited,0,sizeof(visited));
    
    Q.push(make_pair(0,0));
    
    while(!Q.empty()){
      pii act = Q.front();Q.pop();
      if(visited[act.first])continue;
      visited[act.first] = true;
      solution[act.first] = act.second;
      For(j,m){
        int otro = act.first;
        For(p,movs[j].size()){
          otro ^= (1<< (movs[j][p]));
        }
        Q.push(make_pair(otro,act.second+1));
      }
    }
    
    int queries;cin>>queries;
    cout<<"Case "<<(i+1)<<":"<<endl;
    For(j,queries){
      string cad;cin>>cad;
      if(solution.count(fun(cad)) > 0)
        cout<<solution[fun(cad)]<<endl;
      else
        cout<<-1<<endl;
    }
    cout<<endl;
    
  
  }
  return 0;
}

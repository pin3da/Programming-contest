#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,u,v;
  while(cin>>n>>m){
    int g[n+2];
    memset(g,0,sizeof g);


    for(int i = 0; i < m; i++){
      cin >> u >> v;
      g[v]--;
      g[u]++;
    }


    int sol = n+1,cuantos =0;
    int first = -1,second = -1;


    for(int i = 1 ; i <= n; i++){
      if(!g[i])continue;
      if(cuantos == 0 and cuantos+g[i] > 0){
        cuantos += g[i];
        first = i;
      }else if(cuantos + g[i] == 0 ){
        cuantos = 0;
        sol += (i-first)*2;
      }else{
        cuantos += g[i];
      }
    }
    cout<<sol<<endl;
  }
}


using namespace std;
#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<cstdio>
#define For(i,n) for(int i=0;i<(n);++i)
#define foreach(it,x) for(typeof((x).begin()) it  = (x).begin(); it != (x).end(); ++it)
#define all(x) (x).begin(),(x).end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl

void solve(string s){
    vector<string> sufijos;
    string t = s;
    sufijos.push_back(t);
    while (t.size() > 0)
        t.erase(t.begin()), sufijos.push_back(t);
    
    sort(all(sufijos));
    
    int mmax = 0;
    int veces = 2;
    string ans="";
    for(int i=1;i<sufijos.size();++i){
        int j=0;
        while(j<sufijos[i].size() and j<sufijos[i-1].size() and sufijos[i][j]==sufijos[i-1][j])j++;
        
        if(sufijos[i].substr(0,j)==ans)veces++;
        if(j>mmax){
            mmax = j;
            ans= sufijos[i].substr(0,j);
            veces=2;
        }
    }
    if(ans!="")
        cout<<ans<<" "<<veces<<endl;
    else
        cout<<"No repetitions found!"<<endl;
}


int main(){
  int nc; cin>>nc;
  while(nc--){
    string cad;cin>>cad;
    solve(cad);
  }
  return 0;
}

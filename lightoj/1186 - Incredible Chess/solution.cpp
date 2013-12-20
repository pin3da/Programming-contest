using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

string solve(){
  int n;cin>>n;
  vector<int> w(n),b(n);
  for(int i = 0 ; i < n; ++i)
    cin>>w[i];
  for(int i = 0; i < n ; ++i)
    cin>>b[i];
  int ans = 0;
  for(int i = 0; i < n; ++i)
    ans ^= (b[i] - w[i] - 1);

  return (ans == 0)? "black wins" : "white wins";
}

int main(){ ___
  int tc;cin>>tc;
  for(int i = 0; i < tc; ++i){
    cout<<"Case "<<(i+1)<<": "<<solve()<<'\n';
  }

  return 0;
}

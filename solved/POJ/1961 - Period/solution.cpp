using namespace std;
#include<vector>
#include<string>
#include<iostream>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);


vector<int> kmp_preprocess(const string &s){
  vector<int> pi(s.size()+1);
  pi[0] = -1;
  for(int i = 0; i < s.size();++i){
    pi[i+1] = pi[i]; ++i;
    while(pi[i] >= 0 and s[i] != s[pi[i]]) pi[i] = pi[pi[i]];
    pi[i]++;--i;
  }
  return pi;
}

void solve(){
  string cad;cin>>cad;
  vector<int> pi = kmp_preprocess(cad);
  for(int i = 2; i < pi.size(); ++i){
    if(pi[i]==-1) continue;
    int j = i - pi[i];
    if((i % j) == 0)
      cout<<i<<" "<<(i/j)<<'\n';
  }
/*
  for(int i = 0; i < pi.size(); i++) {

    cout<<i<<" "<<i - pi[i]<<" "<<pi[i]<<'\n';
  }
  cout<<'\n';*/
}

int main(){ ___
  int n;
  int tc = 1;
  while(cin>>n and n){
    cout<<"Test case #"<<tc<<'\n';
    solve();tc++;
    cout<<'\n';
  }
  return 0;
}

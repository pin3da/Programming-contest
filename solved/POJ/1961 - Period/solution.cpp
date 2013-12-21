using namespace std;
#include<vector>
#include<string>
#include<iostream>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);


vector<int> kmp_preprocess(const string &s){
  vector<int> pi(s.size());
  pi[0]=-1;
  int k=-1;
  for(int i = 1; i < s.size(); i++){
    while( k >= 0 and  s[k+1] != s[i]) k = pi[k];
    if (s[k+1] == s[i]) k++;
    pi[i] = k;
  }
  return pi;
}

void solve(){
  string cad;cin>>cad;
  vector<int> pi = kmp_preprocess(cad);
  for(int i = 1; i < pi.size(); ++i){
    if(pi[i]==-1) continue;
    int j = i - pi[i];
    if(((i+1) % j) == 0)
      cout<<(i+1)<<" "<<((i+1)/j)<<'\n';
  }
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

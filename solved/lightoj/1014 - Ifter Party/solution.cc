using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MP 50005

void solve(){
  long long p,l;
  cin>>p>>l;
  if ( p - l <= l){
    cout<<" impossible";
    return;
  }
  long long n = p-l;
  long long sn = sqrt(n);
  vector<long long> ans;
  for(int i = 1; i <= sn; ++i)
    if(n%i == 0) {
      ans.push_back(i);
      ans.push_back(n/i);
    }
  sort(ans.begin(),ans.end());
  ans.resize(distance( ans.begin(), unique(ans.begin(),ans.end())) );
  for(int i = 0; i< ans.size(); ++i)
    if(ans[i] > l)cout<<" "<<ans[i];
}

int main(){ ___
  int tc;cin>>tc;
  for(int i = 0; i< tc; ++i){
    cout<<"Case "<<(i+1)<<":";solve();
    cout<<endl;
  }

  return 0;
}

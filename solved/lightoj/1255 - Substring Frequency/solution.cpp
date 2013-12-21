using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl

int solve(){
  string text;
  string p;
  cin>>text>>p;

  //if(text.size() < p.size()) return 0
  int ps = p.size();
  p+='$';
  p+=text;
  int n = p.size();
  vector<int> z(n,0);
  int r = 0, l = 0;
  for(int i = 1; i < n; ++i){
    if(i > r){
      l = r = i;
      while(r < n and p[r-l] == p[r])r++;
      z[i] = r - l; r--;
    }else{
      int k = i -l;
      if(z[k] < r -i + 1) z[i] = z[k];
      else{
        l = i;
        while(r < n and p[r-l] == p[r])r++;
        z[i] = r - l; r--;
      }
    }
  }

  int ans = 0;
  for(int i = ps + 1; i < n; ++i){
    ans += (z[i]==ps);
  }

  return ans;
}

int main(){ ___

  int t;cin>>t;

  for(int i = 0; i< t; ++i)
    cout<<"Case "<<(i+1)<<": "<<solve()<<'\n';

  return 0;
}

// http://codeforces.com/contest/385/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for(int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl

vector<int> compute_z(const string &s){
  int n = s.size();
  vector<int> z(n,0);
  int l,r;
  r = l = 0;
  for(int i = 1; i < n; ++i){
    if(i > r) {
      l = r = i;
      while(r < n and s[r - l] == s[r])r++;
      z[i] = r - l;r--;
    }else{
      int k = i-l;
      if(z[k] < r - i +1) z[i] = z[k];
      else {
        l = i;
        while(r < n and s[r - l] == s[r])r++;
        z[i] = r - l;r--;
      }
    }
  }
  return z;
}

int main() { ___

  string line;
  cin>>line;
  line = "bear$"+line;
  vector<int> z = compute_z(line);
  int seen = 0;
  for ( int i = 5;  i < z.size(); ++i) {
    if(4 == z[i] ) seen = 1;
  }

  if(!seen){
    cout<<0<<endl;
    return 0;
  }
  long long ans = 0;
  int last = 4;
  for ( int i = 5;  i < z.size(); ++i) {
    if(4 == z[i] ) {
      //cout<<"match "<<(i-5)<<endl;
      int left = i - last;
      int right = z.size() - i - 3;
      //D(left);
      //D(right);
      ans += left*right;
      last = i;
    }
  }

  cout<<ans<<endl;



  return 0;
}

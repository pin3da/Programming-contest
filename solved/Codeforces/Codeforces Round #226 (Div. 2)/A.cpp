// http://codeforces.com/contest/385/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for(int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl


int main() { ___

  int n,c;
  cin>>n>>c;
  vector<int> p(n);
  For(i,n) cin>>p[i];

  int diff = 0;
  for (int i = 1; i < n; ++i) {
    diff = max(diff, p[i - 1] - p[i] - c);
  }
  cout<<diff<<endl;

  return 0;
}

// http://codeforces.com/contest/467/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl

int main() { ___

  int n,m, k;
  cin>>n>>m>>k;
  vector<int> p(m + 1);

  for (int i = 0; i < m + 1; ++i) {
    cin>>p[i];
  }
  int ans = 0;
  swap(p[0], p[m]);
  for (int i = 1; i < m + 1; ++i) {
    int cur = p[i] ^ p[0];
    int pc  =  __builtin_popcount(cur);
    if (pc <= k)
      ans++;
  }
  cout << ans << endl;


  return 0;
}
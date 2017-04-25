// http://codeforces.com/contest/402/problem/C

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 20


int main() { ___

  int tc;cin>>tc;
  while (tc--) {
    int n,k;
    cin>>n>>k;
    k = 2*n + k;
    for (int i = 1; i <= n and k; ++i) {
      for (int j = i+1; j <= n and k; ++j) {
        cout<<i<<" "<<j<<endl;
        k--;
      }
    }
  }

  return 0;
}
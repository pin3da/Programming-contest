// http://codeforces.com/contest/388/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 111


int p[MN];
int t[MN];

int main() { ___

  int n;cin>>n;
  For(i,n) cin>>p[i];

  sort (p, p + n);
  memset(t, 0, sizeof t);


  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (t[j] <= p[i]){
        t[j]++;
        ans = max(ans, j);
        break;
      }
    }
  }

  cout<<(ans+1)<<endl;



  return 0;
}
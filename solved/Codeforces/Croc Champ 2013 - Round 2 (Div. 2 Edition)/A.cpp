// http://codeforces.com/contest/299/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 100001


int a[MN];


int main() { ___

  int n;cin>>n;

  int ans = 0, t;
  set<int> seen;
  for (int i = 0; i < n; ++i) {
    cin>>t;
    ans = __gcd(t,ans);
    seen.insert(t);
  }

  if (seen.count(ans)) {
    cout<<ans<<endl;
  } else {
    cout<<-1<<endl;
  }
  return 0;
}
// http://codeforces.com/contest/401/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 111


int nums[MN];

int main() { ___

  int n,x;
  cin>>n>>x;
  int ans = 0;
  int tmp;
  For(i,n) {
    cin>>tmp;
    ans += tmp;
  }

  int mio = 0;
  if (ans > 0) {
    while (ans > 0) {
      ans -= min(ans, x);
      mio++;
    }
  }else {
    while (ans < 0) {
      ans -= max(ans, -x);
      mio++;
    }
  }

  cout<<mio<<endl;
  return 0;
}
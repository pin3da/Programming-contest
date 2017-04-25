// http://codeforces.com/contest/402/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 20


int main() { ___

  int k,a,b,v;
  cin>>k>>a>>b>>v;


  int ans = 0;
  while (b and a > 0) {
    if( b >= (k-1) ) {
      a -= k*v;
      ans++;
      b-=(k-1);
    } else {
      a -= v*(b+1);
      b = 0;
      ans++;
    }
  }

  if (a > 0) {
    ans += (a + v-1)/v;
  }

  cout<<ans<<endl;

  return 0;
}
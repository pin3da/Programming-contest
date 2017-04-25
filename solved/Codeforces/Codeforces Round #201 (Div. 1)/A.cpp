// http://codeforces.com/contest/346/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 100001


int main() { ___

  int n;cin>>n;

  int gcd = 0;
  int mmax = 0;
  int t;
  for (int i = 0; i < n; ++i) {
    cin>>t;
    gcd = __gcd(t,gcd);
    mmax = max (mmax, t);
  }

  int howmany = mmax / gcd;
  int missing = howmany - n;

  if ((missing % 2) == 0) {
    cout<<"Bob"<<endl;
  } else {
    cout<<"Alice"<<endl;
  }
  return 0;
}
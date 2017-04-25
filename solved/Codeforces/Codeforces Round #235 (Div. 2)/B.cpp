// http://codeforces.com/contest/401/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 4004


int d1[MN], d2[MN];

int main() { ___

  int x,k;
  cin>>x>>k;

  int t,a,b;
  memset(d1, 0, sizeof d1);
  memset(d2, 0, sizeof d2);

  For (i,k) {
    cin>>t>>a;
    d2[a] = 1;
    if (t == 1) {
      cin>>b;
      d1[b] = 1;
    }
  }

  int unused = 0;
  int mmin = 0;
  int mmax = 0;
  for (int i = 1; i < x; ++i) {
    if (!d1[i] and !d2[i]) unused++;
    else {
      mmin += (unused + 1)>>1;
      mmax += unused;
      unused = 0;
    }
  }

  mmin += (unused + 1)>>1;
  mmax += unused;
  unused = 0;
  cout<<mmin<<" "<<mmax<<endl;
  return 0;
}
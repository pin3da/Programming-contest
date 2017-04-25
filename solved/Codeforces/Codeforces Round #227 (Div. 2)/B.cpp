// http://codeforces.com/contest/387/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 3333

int pro[MN];
int comp[MN];
int n,m;

int main() { ___

  cin>>n>>m;
  For (i,n) cin>>pro[i];
  For (i,m) cin>>comp[i];

  int i = 0,j = 0;
  while (i < n and j < m) {
    if (pro[i] <= comp[j]) {
      i++;
      j++;
    } else {
      j++;
    }
  }

  cout<<(n-i)<<endl;



  return 0;
}
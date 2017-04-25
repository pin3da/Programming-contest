// http://codeforces.com/contest/136/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 111

int main() { ___
  int n;cin>>n;
  int nums[MN];

  int t;
  For(i, n) {
    cin>>t;
    nums[t-1] = i+1;
  }

  For(i, n)
    cout<<nums[i]<<" ";

  cout<<endl;
  return 0;
}
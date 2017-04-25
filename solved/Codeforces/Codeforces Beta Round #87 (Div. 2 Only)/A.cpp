// http://codeforces.com/contest/116/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 1001


set<int> nums;

int gen(int n) {
  if (n <= 1000) {
    nums.insert(n*10 + 4);
    nums.insert(n*10 + 7);
    gen(n*10 + 4);
    gen(n*10 + 7);
  }
}


int a[MN],b[MN];


int main() { ___

  int n;cin>>n;

  int t, ans = 0;
  int cap = 0;
  for (int i = 0 ; i < n; ++i) {
    cin>>t;
    cap -= t;
    cin>>t;
    cap += t;
    ans = max(ans,cap);
  }

  cout<<ans<<endl;
  return 0;
}
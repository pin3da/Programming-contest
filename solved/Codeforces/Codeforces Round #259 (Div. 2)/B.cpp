// http://codeforces.com/contest/454/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl


int main() { ___

  int n;cin>>n;
  int nums[n];
  For (i,n) cin>>nums[i];

  int j = 0;

  for (int i = 0 ; i + 1 < n; ++i , ++j) {
    if (nums[i] > nums[i + 1]) {
      break;
    }
  }


  int next = 0;
  int ans = 0;
  for (int k = n - 1; k > j; --k) {
    if (nums[next] < nums[k]) {
      cout<<-1<<endl;
      return 0;
    }
    ans++;
    next = k;
  }
  cout<<ans<<endl;

  return 0;
}
using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 111


int main() { ___

  int n;
  while (cin>>n) {
    vector<int> nums(n);
    int zero = 0;
    for (int i = 0; i < n; ++i) {
      cin>>nums[i];
      if (!nums[i])
        zero++;
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      if (!nums[i])
        zero--;
      else
        ans += zero;
    }
    cout<<ans<<endl;
  }
  return  0;
}

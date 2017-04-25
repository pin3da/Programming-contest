// http://codeforces.com/contest/59/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 100001


int main() { ___

  int n;cin>>n;

  vector<int> odd, even;
  int t;
  for (int i = 0; i < n; ++i) {
    cin>>t;
    if (t & 1) even.push_back(t);
    else odd.push_back(t);
  }

  sort(odd.begin(), odd.end());
  sort(even.begin(), even.end());

  int i = (even.size() > 0 and (even.size()%2 == 0)) ? 1 : 0;

  int ans = 0;
  for (; i < even.size(); ++i) ans += even[i];


  if (even.size() > 0)
    for (i = 0; i < odd.size(); ++i)
      ans += odd[i];


  cout<<ans<<endl;

  return 0;
}
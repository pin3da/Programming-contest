// http://codeforces.com/contest/463/problem/B

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = " << (x) <<endl
#define endl '\n'

int main() { ___

  int n;

  while (cin>>n) {
    vector<int> all(n);
    for (int i = 0; i < n; ++i)
       cin>> all[i];

    long long accum = 0;
    long long ans = all[0];
    for (int i = 0; i < n - 1; ++i) {
      accum += all[i] - all[i+1];
      if (accum < 0) {
        ans += fabs(accum);
        accum = 0;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
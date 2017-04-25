// http://codeforces.com/contest/433/problem/B

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = " << (x) <<endl
#define endl '\n'


long long get(const vector<long long> &image, int l, int r) {
  long long ans = image[r];
  if (l) ans -= image[l - 1];
  return ans;
}


int main() { ___


  int n;cin>>n;
  vector<long long> all(n);
  vector<long long> sum(n, 0);
  vector<long long> add(n, 0);

  for (int i = 0; i < n; ++i)
    cin>>all[i];

  sum[0] = all[0];
  for (int i = 1; i < n; ++i)
    sum[i] = sum[i - 1] + all[i];

  sort(all.begin(), all.end());
  add[0] = all[0];
  for (int i = 1; i < n; ++i)
    add[i] = add[i - 1] + all[i];

  int q;cin>>q;
  while (q--) {
    int type, l, r;
    cin>>type>>l>>r;
    if (type == 1)
      cout<<get(sum, l - 1, r - 1)<<endl;
    else
      cout<<get(add, l - 1, r - 1)<<endl;
  }

  return 0;
}
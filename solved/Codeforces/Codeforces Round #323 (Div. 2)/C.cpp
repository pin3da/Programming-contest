// http://codeforces.com/contest/583/problem/C

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, t; cin >> n;
  map<int, int> a;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> t;
      a[t]++;
    }
  }

  vector<int> ans;
  while (ans.size() < n) {
    int cur =  a.rbegin()-> first;
    a[cur]--;
    if (a[cur] == 0) {
      a.erase(cur);
    }
    for (int i = 0; i < ans.size(); ++i) {
      int gen = __gcd(ans[i], cur);
      assert(a.count(gen));
      a[gen]-= 2;
      if (a[gen] == 0) {
        a.erase(gen);
      }
    }
    ans.push_back(cur);
  }

  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
// http://codeforces.com/contest/489/problem/A

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

int main() { ___

  int n;
  cin >> n;
  vector<int> num(n);
  for (int i = 0; i < n; ++i) {
    cin >> num[i];
  }


  vector<int> ans;
  for (int i = 0; i < n; ++i) {

    int mmin = INT_MAX;
    int idx = 0;
    for (int j = i; j < n; ++j) {
      if (num[j] < mmin) {
        mmin = num[j];
        idx = j;
      }
    }
    if (idx != i) {
      ans.push_back(i);
      ans.push_back(idx);
      swap(num[i], num[idx]);
    }
  }

  cout << ans.size() / 2 << endl;
  for (int i = 0; i < ans.size(); i += 2) {
    cout << ans[i] << " " << ans[i + 1] << endl;
  }

  return 0;
}
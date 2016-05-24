#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<int> ans(2);
    int t;
    for (int i = 0; i < n; ++i) {
      cin >> t;
      ans[t]++;
    }
    cout << (ans[0] > ans[1] ? 'Y' : 'N') << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    vector<int> a(n);
    vector<int> ans(2);
    for (auto &i : a) {
      cin >> i;
      ans[i]++;
    }
    cout << "Mary won " << ans[0] << " times and John won " << ans[1] << " times"<< endl;
  }
  return 0;
}

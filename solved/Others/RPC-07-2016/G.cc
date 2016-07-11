#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 1000001;

int f(int n) {
  int ans = 0;
  while (n > 0) {
    ans += n % 10;
    n /= 10;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  vector<pair<int, int>> ans;
  for (int i = 0; i < MN; ++i) {
    ans.emplace_back(f(i), i);
  }
  sort(ans.begin(), ans.end());

  string line;
  while (cin >> line && line != "END") {
    int q = stoi(line);
    int qq = f(q);
    pair<int, int> tar(qq - 1, q - 1);
    auto it = lower_bound(ans.begin(), ans.end(), tar);
    while (it-> second >= q || it-> first >= qq)
      it--;
    cout << it-> second << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  vector<int> ans;
  int a, b;
  while (cin >> a >> b) {
    ans.emplace_back(__gcd(a, b));
    if (ans.back() > 5)
      cout << "Noel" << endl;
    else
      cout << "Gnomos" << endl;
  }

  reverse(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}

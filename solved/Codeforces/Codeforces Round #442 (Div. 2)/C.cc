#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int n;
  cin >> n;
  vector<int> ans;

  for (int i = 1; i < n; i += 2)
    ans.push_back(i + 1);

  for (int i = 0; i < n; i += 2)
    ans.push_back(i + 1);

  for (int i = 1; i < n - 1; i += 2)
    ans.push_back(i + 1);

  if (!(n & 1)) ans.push_back(n);

  cout << ans.size() << endl;
  for (int i : ans)
    cout << i << " ";

  cout << endl;
  return 0;
}

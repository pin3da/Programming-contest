#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int n;
  cin >> n;
  vector<string> data(n);
  for (string &i : data)
    cin >> i;

  sort(data.begin(), data.end(), [](const string &a, string &b) {
    if (a.size() != b.size()) {
      return a.size() < b.size();
    } else {
      return a < b;
    }
  });

  for (string &i : data)
    cout << i << endl;

  return 0;
}

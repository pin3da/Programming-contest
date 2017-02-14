#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  vector<pair<string, string>> a(n);
  for (auto &i : a)
    cin >> i.second >> i.first;

  sort(a.begin(), a.end());
  for (auto i : a)
    cout << i.second << " " << i.first << endl;
  return 0;
}

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  vector<int> a(3);
  for (auto &i : a) cin >> i;
  vector<int> b = a;
  sort(a.begin(), a.end());
  for (auto &i : a) cout << i << endl;
  cout << endl;
  for (auto &i : b) cout << i << endl;
  return 0;
}

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  vector<int> a(100);
  for (auto &i : a)
    cin >> i;
  cout << *max_element(a.begin(), a.end()) << endl;
  cout << max_element(a.begin(), a.end()) - a.begin() + 1 << endl;
  return 0;
}

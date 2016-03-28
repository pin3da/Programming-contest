#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int l;
  while (cin >> l) {
    vector<int> a(l);
    for (auto &i : a) cin >> i;
    int p = *max_element(a.begin(), a.end());
    if (p < 10)
      cout << 1;
    else if (p < 20)
      cout << 2;
    else
      cout << 3;
    cout << endl;
  }
  return 0;
}

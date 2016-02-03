#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    vector<pair<int, int>> a(n);
    for (int i = 0; i < a.size(); ++i) {
      cin >> a[i].first;
      a[i].second = i + 1;
    }

    sort(a.rbegin(), a.rend());
    cout << a[1].second << endl;
  }
  return 0;
}


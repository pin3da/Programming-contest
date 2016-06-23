#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

void move(vector<int> &a, int b, int e) {
    cout << e << ' ' << e + 1 << endl;
    swap(a[e - 1], a[e]);
    if ((e - b) == 1)  return;
    move(a, b, e - 1);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<int> a(n);
    for (auto &i: a)  cin >> i;
    vector<int> b = a;
    sort(b.begin(), b.end());
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] == b[i]) continue;
      for (int j = i + 1; j < a.size(); ++j) {
        if (a[j] == b[i]) {
          move(a, i, j);
          break;
        }
      }
    }
  }
  return 0;
}

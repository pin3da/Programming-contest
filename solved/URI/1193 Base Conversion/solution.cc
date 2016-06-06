#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

string bs[] = {"dec", "hex", "bin"};
int bv[] = {10, 16, 2};

void print(long long n, int i) {
  deque<int> a;
  while (n > 0) {
    a.push_front(n % bv[i]);
    n /= bv[i];
  }
  for (auto &i : a) {
    if (i >= 10)
      cout << char('a' + i - 10);
    else
      cout << i;
  }
}

void solve() {
  string n, base;
  cin >> n >> base;
  long long num;
  for (int i = 0; i < 3; ++i) {
    if (base == bs[i])
      num = stoll(n, 0, bv[i]);
  }
  for (int i = 0; i < 3; ++i) {
    if (base != bs[i]) {
      print(num, i);
      cout << " " << bs[i] << endl;
    }
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    cout << "Case " << (i + 1) << ":" << endl;
    solve();
  }
  return 0;
}

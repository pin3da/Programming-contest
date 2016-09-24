#include <bits/stdc++.h>


#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const int MN = 5000 + 100;

int n, l, c;

int a[MN];
bool solve() {
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  reverse(a, a + n);
  int i = 0;
  while (i < n) {
    int cur_w = a[i];
    if (cur_w > c) return false;
    c -= cur_w;
    int count = 1;
    while (count <= l && i < n) {
      count++;
      i++;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  while (cin >> n >> l >> c) {
    puts(solve() ? "S" : "N");
  }
  return 0;
}

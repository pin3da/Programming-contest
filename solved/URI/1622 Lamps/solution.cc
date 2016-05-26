#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int find_c(int k, int n) {
  int ans = 1;
  int id = k;
  while (id != 0) {
    ans++;
    id = (id + k) % n;
  }
  return ans;
}

void toggle(char &a) {
  a = a == 'x' ? 'o' : 'x';
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, q;
  while (cin >> n >> q) {
    string line; cin >> line;
    int last = 0, k, m;
    while (q--) {
      cin >> k >> m;
      int p = find_c(k, n) * 2;
      m %= p;
      last = 0;
      string tmp = line;
      while (m--) {
        toggle(tmp[last]);
        last = (last + k) % n;
      }
      cout << tmp << endl;
    }
  }
  return 0;
}

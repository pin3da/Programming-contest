#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int all[1 << 16 + 10];

int conv(string &s) {
  int ans = 0;
  for (int i = 0; i < s.size(); ++i) {
    ans <<= 1;
    ans |= (s[i] == '1');
  }
  return ans;
}

void apply(int mask, int x, int t) {
  for (int i = mask; i > 0; i = (i - 1) & mask) {
    if (t == 1)
      all[i] = x;
    else
      all[i] ^= x;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int t, x, s; cin >> t;
    string q;
    if (t == 1) {
      cin >> x >> q;
      s = conv(q);
      apply(s, x, 1);
    }
    if (t == 2) {
      cin >> x >> q;
      s = conv(q);
      apply(s, x, 2);
    }

    if (t == 3) {
      cin >> q;
      s = conv(q);
      cout << all[s] << endl;
    }
  }

  return 0;
}

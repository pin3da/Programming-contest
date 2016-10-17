#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 1234;
int bucket[MN];
int bef[MN];

const long long mod = 1e9 + 7;

bool palindrome(string s) {
  for (size_t i = 0; i < s.size() / 2; ++i)
    if (s[i] != s[s.size() - 1 - i]) return false;
  return true;
}

long long go(vector<string> &a, int totlen) {
  int ans = 0;
  for (int mask = 0; mask < (1 << totlen); ++mask) {
    set<int> b;
    vector<int> ids;
    for (int i = 0; i < totlen; ++i) {
      if ((mask >> i) & 1) {
        b.insert(bucket[i]);
        ids.push_back(i);
      }
    }
    if (b.size() == a.size()) {
      string cur;
      for (size_t i = 0; i < ids.size(); ++i) {
        int j = bucket[ids[i]];
        int pos = ids[i] - bef[j];
        cur.push_back(a[j][pos]);
      }
      if (palindrome(cur)) {
        debug(cur);
        ans++;
      }
    }
  }
  return ans;
}

void solve() {
  int n; cin >> n;
  vector<string> a(n);
  int totlen = 0;
  memset(bucket, -1, sizeof bucket);
  memset(bef, 0, sizeof bef);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i) bef[i] = bef[i - 1] + a[i - 1].size();
    for (size_t k = 0; k < a[i].size(); ++k) {
      bucket[totlen++] = i;
    }
  }
  cout << go(a, totlen) << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#endif
  int tc; cin >> tc;
  while (tc--)
    solve();
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

char inv(char k, char c) {
  int a = k - 'a';
  int b = c - 'a';
  int ans = (b - a + 26) % 26;
  return ans + 'a';
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;
  string key, ciphered;
  cin >> key >> ciphered;

  string tmp = key;

  reverse(key.begin(), key.end());
  reverse(ciphered.begin(), ciphered.end());

  string ans;

  int cur = 0;
  while (key.size() < ciphered.size()) {
    ans.push_back(inv(key[cur], ciphered[cur]));
    cur++;
    key.push_back(ans.back());
  }

  reverse(ans.begin(), ans.end());
  cout << ans << tmp << endl;

  return 0;
}

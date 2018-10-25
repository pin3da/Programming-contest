#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n;
  cin >> n;
  vector<int> id(n), w(n), seen(n);
  for (int i = 0; i < n; i++) {
    cin >> id[i];
    id[i]--;
    w[id[i]] = i;
  }

  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    c--;

    int ans = 0;
    for (int j = w[c]; j >= 0 && seen[id[j]] == 0; j--) {
      seen[id[j]] = true;
      ans++;
    }
    cout << ans << " ";
  }

  cout << endl;


  return 0;
}

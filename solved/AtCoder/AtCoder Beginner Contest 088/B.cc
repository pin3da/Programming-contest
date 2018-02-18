#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif


void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(a.begin(), a.end());

  long long total = accumulate(a.begin(), a.end(), 0);

  long long op1 = 0, op2 = 0;
  for (int i = 0; i < n; i += 2)
    op1 += a[i];
  for (int i = n - 1; i >= 0; i -= 2)
    op2 += a[i];

  if (op1 < op2) {
    swap(op1, op2);
  }
  long long b = total - op1;
  cout << op1 - b << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
  solve();
  return 0;
}


#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif


void solve() {
  int n; cin >> n;
  vector<int> a(n);
  read(a);

  sort(a.begin(), a.end());
  vector<int> val(3);

  set<int> v;
  for (int i = 0; i < n; i++) {
    val[a[i] - a[0]]++;
    v.insert(a[i]);
  }

  vector<int> real(v.begin(), v.end());
  if (val[0] && val[2]) {
    if (!val[1]) {
      real[2] = real[1];
      real[1] = real[0] + 1;
    }
  }

  debug(real[0], real[1], real[2]);

  vector<int> b = a;
  if (val[0] && val[2] && ((val[1] - (val[1]&1)) > 2 * min(val[0], val[2]))) {
    while (val[1] >= 2) {
      val[1] -= 2;
      val[2]++;
      val[0]++;
    }
  } else {
    while (val[0] && val[2]) {
      val[0]--;
      val[2]--;
      val[1] += 2;
    }
  }

  int pos = 0;
  for (int i = 0; i < 3; i++) {
    while (val[i]--)
      b[pos++] = real[i];
  }

  assert(pos == n);

  int mia = *min_element(a.begin(), a.end());
  int mib = *min_element(b.begin(), b.end());
  int maa = *max_element(a.begin(), a.end());
  int mab = *max_element(b.begin(), b.end());

  assert(mia <= mib && mab <= maa);

  map<int, int> fa, fb;
  set<int> all;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    fa[a[i]]++;
    fb[b[i]]++;
    all.insert(a[i]);
    all.insert(b[i]);
  }

  for (auto it : all) {
    ans += min(fa[it], fb[it]);
  }

  cout << ans << endl;
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << b[i];
  }
  cout << endl;

  assert(accumulate(a.begin(), a.end(), 0LL) == accumulate(b.begin(), b.end(), 0LL));
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


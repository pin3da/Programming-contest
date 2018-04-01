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

  vector<int> expected = a;
  sort(expected.rbegin(), expected.rend());
  vector<int> ans;

  while (a.size()) {
    for (int i = 1; i < int(a.size()); i++) {
      if (a[i] - a[i - 1] > 1) {
        a[i]--;
        a[i - 1]++;
      } else if (a[i - 1] - a[i] > 1) {
        a[i - 1]--;
        a[i]++;
      }
    }
    int id = 0;
    for (int i = 0; i < int(a.size()); i++) {
      if (a[i] > a[id]) {
        id = i;
      }
    }
    ans.push_back(a[id]);
    a.erase(a.begin() + id);
  }

  puts (ans == expected ? "YES" : "NO");
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


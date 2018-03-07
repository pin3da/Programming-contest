// WA
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


bool intersect(int a, int b, int c, int d) {
  if (c >= a && c <= b) return true;
  if (d >= a && d <= b) return true;
  if (a >= c && a <= d) return true;
  if (b >= c && b <= d) return true;
  return false;
}

void solve() {
  int n; cin >> n;

  set<pair<int, int>> by_start, by_end;

  while (n--) {
    int t; cin >> t;
    if (t == 1) {
      int a, b; read(a, b);
      by_start.insert({a, b});
      by_end.insert({b, a});
    }

    if (t == 2) {
      int a, b; read(a, b);
      by_start.erase({a, b});
      by_end.erase({b, a});
    }

    if (t == 3) {
      int a, b, c, d;
      read(a, b, c, d);

      if (a == c && b == d) {
        cout << 0 << endl;
      } else {
        if (intersect(a, b, c, d)) {
          int rig = max(b, d);
          int lef = min(a, c);
          int has_left = false;
          if (by_end.size()) {
            auto first = *by_end.begin();
            if (first.first < lef)
              has_left = true;
          }

          int has_right = false;
          if (by_start.size()) {
            auto first = by_start.lower_bound({rig + 1, 0});
            if (first != by_start.end())
              has_right = true;
          }


          if (has_left || has_right)
            cout << 2 << endl;
          else
            cout << -1 << endl;

        } else {
          cout << 1 << endl;
        }
      }
    }
  }
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


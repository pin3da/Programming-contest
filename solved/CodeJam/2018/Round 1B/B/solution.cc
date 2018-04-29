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

struct sign {
  int p, a, b;
};

bool test(vector<sign> &all, int start, int end) {
  set<int> N;
  vector<pair<int, int>> p;
  for (int i = start; i <= end; i++) {
    p.emplace_back(all[i].p + all[i].a, all[i].p - all[i].b);
    N.insert(all[i].p + all[i].a);
  }

  for (auto a : N) {
    set<int> other;
    int ok = true;
    for (auto it : p) {
      if (it.first != a) {
        other.insert(it.second);
        if (other.size() > 1) {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      return true;
    }
  }
  return false;
}

void solve() {
  int n; cin >> n;
  vector<sign> all(n);
  for (auto &i : all) {
    cin >> i.p >> i.a >> i.b;
  }

  int best = 0, frec = 0;
  for (int i = 0; i < n; i++) {
    int lo = i, hi = n - 1;

    if (test(all, i, hi)) {
      if (hi - i + 1 == best) {
        frec++;
      } else if (hi - i + 1 > best) {
        best = hi - i + 1;
        frec = 1;
      }
      continue;
    }

    while (lo < hi) {
      int mid = (lo + hi + 1) >> 1;
      if (test(all, i, mid)) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }

    if (lo - i + 1 == best) {
      frec++;
    } else if (lo - i + 1 > best) {
      best = lo - i + 1;
      frec = 1;
    }


    /*
       for (int j = i; j < n; j++) {
       if (test(all, i, j)) {
       if (j - i + 1 == best) {
       frec++;
       } else if (j - i + 1 > best) {
       best = j - i + 1;
       frec = 1;
       }
       } else {
       break;
       }
       }*/
  }
  cout << best << " " << frec << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }
  return 0;
}


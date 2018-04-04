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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
using namespace std;
using namespace __gnu_pbds;
typedef pair<long long, long long> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> OST;

const long long MY = 2000000000LL;
const int N = 200001 + 100;

OST bit[N];

void insert(int x, long long y) {
  for(int i = x; i < N; i += i & -i)
    bit[i].insert(mp(y, x));
}

long long query(int x, long long y) {
  long long ans = 0;
  for(int i = x; i > 0; i -= i & -i)
    ans += bit[i].order_of_key(mp(y+1, 0));
  return ans;
}

long long make_query(int x1, int x2, int y1, int y2) {
  long long ans = query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
  return ans;
}

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  read(a);
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    /*
       for (int j = i + 1; j < min(a[i], n); j++) {
       if (a[j] >= i) ans++;
       }
       */
    ans += make_query(i + 2, min(a[i], n), i + 1, MY);
    insert(i + 1, a[i]);
  }
  cout << ans << endl;
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


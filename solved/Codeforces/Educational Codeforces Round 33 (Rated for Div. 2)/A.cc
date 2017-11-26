#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int losser(int winner, int e) {
  for (int i = 1; i < 4; i++) {
    if (i != winner && i != e)
      return i;
  }
  assert(false);
  return -1;
}

bool possible(vector<int> &a, int e) {
  for (int i = 0; i < (int)a.size(); i++) {
    if (a[i] == e) return false;
    e = losser(a[i], e);
  }
  return true;
}


int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  int ok = (possible(a, 3));
  puts(ok ? "YES" : "NO");
  return 0;
}

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; cin >> n;
  vector<long long> a(n);
  for (auto &i : a) cin >> i;
  int i = 0;
  unordered_set<int> s;
  while (i >= 0 && i < n) {
    s.insert(i);
    if (a[i] & 1) {
      if (a[i])
        a[i]--;
      ++i;
    } else {
      if (a[i])
        a[i]--;
      --i;
    }
  }
  long long total = accumulate(a.begin(), a.end(), 0LL);
  cout << s.size() << " " << total << endl;

  return 0;
}

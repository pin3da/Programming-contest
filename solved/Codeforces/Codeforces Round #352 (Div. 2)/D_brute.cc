#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n, k;
  while (cin >> n >> k) {
    map<int, int> s;
    while (n--) {
      int t; cin >> t;
      s[t]++;
    }

    while (k--) {
      int a = (s.begin())-> first;
      auto e = s.end();
      e--;
      int b = e-> first;
      if (a < b) {
        s[a]--;
        s[b]--;
        if (s[a] == 0) s.erase(a);
        if (s[b] == 0) s.erase(b);
        s[++a]++;
        s[--b]++;
      }
    }
    int a = (s.begin())-> first;
    auto e = s.end();
    e--;
    int b = e-> first;
    cout << b - a << endl;

  }
  return 0;
}

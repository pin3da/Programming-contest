#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

const long long inf =  100000LL * 100000LL;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];

    vector<int> iz(n), der(n);
    int last = 0;
    for (int i = 0; i < n; ++i) {
      iz[i] = min(last + 1, a[i]);
      last = iz[i];
    }
    last = 0;
    for (int i = n - 1; i > 0; --i) {
      der[i] = min(last + 1, a[i]);
      last = der[i];
    }

    int best = 0;
    for (int i = 0; i < n; ++i) {
      best = max(best, min(iz[i], der[i]));
    }
    cout << best << endl;
  }
  return 0;
}

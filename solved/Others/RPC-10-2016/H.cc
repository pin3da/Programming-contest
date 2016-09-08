#include <bits/stdc++.h>

using namespace std;
// #define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

const int MN = 50000000;

long long tri[1000000];
int total = 0;

long long fun(long long x) {
  return (x * (x + 1)) >> 1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  for (long long i = 0; fun(i) <= MN; ++i) {
    tri[total++] = fun(i);
  }

  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    if (binary_search(tri, tri + total, n)) {
      cout << (int)(lower_bound(tri, tri + total, n) - tri - 1) << endl;
    } else {
      cout << "No solution" << endl;
    }
  }

  return 0;
}

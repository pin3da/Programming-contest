// http://codeforces.com/contest/513/problem/B2

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() { ___

  int n;
  long long m; cin >> n >> m;

  vector<long long> val(n);
  long long pot = 1LL << max(n - 2, 0);
  for (int i = 0; i < n; ++i) {
    val[i] = pot;
    pot = max(1LL, pot >> 1);
  }
  vector<int> seen(n, 0);


  while (true) {
    int fin = true;
    for (int i = 0; i < n; ++i) {
      if (!seen[i])
        fin = false;
    }

    if (fin)
      break;

    int last = -1;
    long long accum = 0;
    int cool = 0;
    for (int i = 0; i < n; ++i) {
      if (!seen[i]) {
        accum += val[i];
        last = i;
        if (accum >= m) {
          cout << i + 1 << " ";
          seen[i] = 1;
          cool = true;
          break;
        }
      }
    }
    if (last > -1 and !cool) {
      cout << last + 1 << " ";
      seen[last] = true;
    }
  }

  cout << endl;

  return 0;
}

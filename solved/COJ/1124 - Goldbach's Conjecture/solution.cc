#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

const int MN = 1000000 + 100;
int sieve[MN];

vector<int> p;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  sieve[0] = sieve[1] = 1;
  for (int i = 2; i < MN; ++i) {
    if (!sieve[i]) {
      p.push_back(i);
      for (int j = i + i; j < MN; j += i)
        sieve[j] = 1;
    }
  }

  int n;
  while (cin >> n && n) {
    for (auto &i: p) {
      if (!sieve[n - i]) {
        cout << n << " = " << min(n - i, i) << " + " << max(n - i, i) << endl;
        break;
      }
    }
  }
  return 0;
}

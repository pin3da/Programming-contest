#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;
const int M = 50000000;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  vector<long long> all;
  for (long long i = 1; i <= M; ++i)
    all.push_back(i * i);

  long long n;
  while (cin >> n) {
    n *= n;
    int seen = 0;
    for (int i = 0; i < M; ++i) {
      long long b = n - all[i];
      if (binary_search(all.begin(), all.end(), b)) {
        cout << b << ' ' << all[i] << endl;
        seen = true;
        break;
      }
      b = n + all[i];
      if (binary_search(all.begin(), all.end(), b)) {
        cout << b << ' ' << all[i] << endl;
        seen = true;
        break;
      }
    }
    if (!seen) cout << - 1 << endl;
  }
  return 0;
}

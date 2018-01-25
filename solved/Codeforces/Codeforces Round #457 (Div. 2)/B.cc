#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  long long n, k;
  cin >> n >> k;
  map<int, long long> frec;
  int total = 0;
  int cur = 0;
  while (n > 0) {
    if (n & 1) {
      frec[cur]++;
      total++;
    }
    n >>= 1;
    cur++;
  }

  if (total > k) {
    cout << "No" << endl;
    return 0;
  }

  for (int i = 65; i > -65; i--) {
    if (frec[i] + total <= k) {
      frec[i - 1] += 2 * frec[i];
      total += frec[i];
      frec[i] = 0;
    } else {
      break;
    }
  }

  multiset<int> powers;
  for (int i = 65; i > -65; i--) {
    for (int j = 0; j < frec[i]; j++)
      powers.insert(i);
  }

  while (int(powers.size()) < k) {
    int cur = *powers.begin(); powers.erase(powers.begin());
    powers.insert(cur - 1);
    powers.insert(cur - 1);
  }

  cout << "Yes" << endl;
  while (powers.size()) {
    cout << *(--powers.end())<< " ";
    powers.erase(--powers.end());
  }
  cout << endl;
  return 0;
}

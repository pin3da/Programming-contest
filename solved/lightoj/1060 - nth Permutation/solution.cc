using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

long long fact[22];

long long ways(vector<int> &c) {
  long long den = 1, total = 0;
  for (int i = 0; i < c.size(); ++i) {
    den *= fact[c[i]];
    total += c[i];
  }

  return fact[total] / den;
}

void solve() {
  string line;
  int n;
  cin >> line >> n;
  vector<int> frec(30);
  for (int i = 0; i < line.size(); ++i)
    frec[line[i] - 'a']++;

  if (ways(frec) < n) {
    puts("Impossible");
    return;
  }

  for (int i = 0; i < line.size(); ++i) {
    for (int j = 0; j < frec.size(); ++j) {
      if (frec[j]) {
        frec[j]--;
        if (ways(frec) >= n) {
          putchar('a' + j);
          break;
        } else {
          n -= ways(frec);
          frec[j]++;
        }
      }
    }
  }
  putchar('\n');
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  fact[0] = 1;
  for (long long i = 1; i < 22; ++i)
    fact[i] = fact[i - 1] * i;

  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}

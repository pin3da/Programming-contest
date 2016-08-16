#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 22;
long long fact[MN];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  fact[0] = 1;
  for (long long i = 1; i < MN; ++i)
    fact[i] = i * fact[i - 1];

  int n, m, c;
  cin >> n >> m >> c;
  int a = n + m - c - 1;
  cout << fact[a] << endl;
  return 0;
}

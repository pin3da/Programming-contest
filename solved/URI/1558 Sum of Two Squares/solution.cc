#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 10000 + 10;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  vector<int> sieve(MN);

  for (int i = 0; i * i < MN; ++i)
    for (int j = 0; i * i + j * j < MN; ++j)
      sieve[i * i + j * j] = true;

  int n;
  while (cin >> n)
    if (n < 0) cout << "NO" << endl;
    else       cout << (sieve[n] ? "YES" : "NO") << endl;
  return 0;
}

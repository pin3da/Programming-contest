#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  vector<unsigned long long> fib(61);
  fib[0] = 0; fib[1] = 1;
  for (int i = 2; i < 61; ++i)
    fib[i] = fib[i - 1] + fib[i - 2];

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    if (i) cout << " ";
    cout << fib[i];
  }
  cout << endl;
  return 0;
}

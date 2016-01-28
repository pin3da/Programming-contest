#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n;
  cin >> n;
  for (int i = 1; i < 11; ++i)
    printf("%d x %lld = %lld\n", i, n, i * n);
  return 0;
}

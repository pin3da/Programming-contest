#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t;
  cin >> t;
  while (t-- > 0) {
    long long n;
    cin >> n;
    int prime = true;
    for (long long i = 2; i * i <= n && prime; ++i) {
      if (n % i) continue;
      prime = false;
    }
    if (prime) cout << n << " eh primo" << endl;
    else cout << n << " nao eh primo" << endl;
    // printf("%d %seh primo\n", n, (prime ? "" : "nao "));
  }
  return 0;
}

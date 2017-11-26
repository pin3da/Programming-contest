#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  vector<long long> numbers;
  for (int i = 0; i < 15; i++) {
    numbers.push_back(((1LL << (i + 1)) - 1) * (1LL << i));
  }

  long long n;
  cin >> n;
  long long ans = 1;
  for (int i = 0; i < (int)numbers.size(); i++) {
    if ((n % numbers[i]) == 0) ans = numbers[i];
  }
  cout << ans << endl;

  return 0;
}

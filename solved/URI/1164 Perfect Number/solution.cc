#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;  cin >> n;
  while (n--) {
    long long x; cin >> x;
    vector<int> divs;
    for (int i = 1; i * i <= x; ++i) {
      if ((x % i) == 0) {
        divs.emplace_back(i);
        if ((x / i) != i)
          divs.emplace_back(x / i);
      }
    }

    cout << x << ' ';
    if (accumulate(divs.begin(), divs.end(), 0) == x + x)
      cout << "eh perfeito" << endl;
    else
      cout << "nao eh perfeito" << endl;
  }

  return 0;
}

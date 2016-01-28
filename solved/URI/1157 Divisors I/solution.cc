#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n;
  cin >> n;
  vector<long long> ans;
  ans.reserve(n);
  for (int i = 1; i * i <= n; ++i) {
    if (n % i) continue;
    ans.push_back(i);
    if ((n / i) == i) continue;
    ans.push_back(n / i);
  }
  sort(ans.begin(), ans.end());
  for (auto &i : ans)
    cout << i << endl;
  return 0;
}

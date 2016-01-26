#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  vector<int> a(20);
  for (auto &i : a)
    cin >> i;

  reverse(a.begin(), a.end());

  for (int i = 0; i < 20; ++i)
    cout << "N[" << i << "] = " << a[i] << endl;
  return 0;
}

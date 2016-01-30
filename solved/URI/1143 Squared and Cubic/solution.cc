#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cout << i << " " << i * i << " " << i * i * i << endl;
  return 0;
}

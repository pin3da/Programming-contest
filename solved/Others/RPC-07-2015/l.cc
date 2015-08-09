using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    cout << (1LL << n) - 1 << endl;
  }

  return 0;
}

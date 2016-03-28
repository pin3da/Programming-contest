#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    long long t; cin >> t;
    if (t == 0) {
      cout << "NULL" << endl;
      continue;
    }
    if (t & 1)
      cout << "ODD ";
    else
      cout << "EVEN ";

    if (t < 0)
      cout << "NEGATIVE" << endl;
    else
      cout << "POSITIVE" << endl;
  }
  return 0;
}

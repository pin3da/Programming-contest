#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  for (int i = 1; i <= 3 * 3; i += 2) {
    for (int j = 7; j > 4; --j)
      cout << "I=" << i << " J=" << j << endl;
  }
  return 0;
}

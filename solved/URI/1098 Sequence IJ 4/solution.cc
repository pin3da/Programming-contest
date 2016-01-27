#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  for (double i = 0; i <= 2.01; i += 0.2)
    for (double j = 1; j <= 3; j += 1)
      cout << "I=" << i << " J=" << j + i << endl;
  return 0;
}

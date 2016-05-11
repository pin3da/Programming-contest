#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
const int MN = 200 + 10;

int sum[MN];
int seq[MN * MN];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  sum[0] = 1;
  int k = 1;
  for (int i = 1; i < MN; ++i) {
    sum[i] = sum[i - 1] + i;
    for (int j = 0; j < i; ++j)
      seq[k++] = i;
  }

  int n, tc = 1;
  while (cin >> n) {
    cout << "Caso " << tc++ << ": " << sum[n] << " numero" << (sum[n] > 1 ? "s" : "") << endl;
    for (int i = 0; i < sum[n]; ++i) {
      if (i) cout << " ";
      cout << seq[i];
    }
    cout << endl << endl;
  }
  return 0;
}

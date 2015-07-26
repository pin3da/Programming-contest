using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

typedef unsigned long long ull;

const int MN = (5 * 1000000) + 100;
ull ans[MN + 1];
int phi[MN + 1];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  for (int i = 1; i <= MN; i += 2) phi[i] = i;
  for (int i = 2; i <= MN; i += 2) phi[i] = i / 2;
  for (int i = 3; i <= MN; i += 2)
    if (phi[i] == i) {
      phi[i]--;
      for (int j = i + i; j <= MN; j += i) phi[j] -= phi[j] / i;
    }

  for (int i = 1; i <= MN; i++) ans[i] = 1;
  for (int i = 2; i <= MN; i++)
    for (int j = i; j <= MN; j += i)
      ans[j] += ull(phi[i]) * i;

  for (int i = 1; i <= MN; i++)
    ans[i] = ((ans[i] - 1)/ 2 * i) + ans[i - 1];

  int tc, t;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    cin >> t;
    printf("Case %d: %llu\n", i + 1, ans[t]);
  }

  return 0;
}

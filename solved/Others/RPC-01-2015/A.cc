using namespace std;
#include <bits/stdc++.h>

const int mod = 1000000007;
const int MN = 100011;
long long ans[MN];

int main() {
	ans[0] = ans[1] = 1;
	for (int i = 2; i < MN; ++i) {
		ans[i] = (ans[i - 1] * i)  % mod;
	}
	for (int i = 0; i < MN; ++i) {
		ans[i] = (ans[i] - 1 + mod) % mod;
	}
	int t, n;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n;
		cout << ans[n] << endl;
	}
  return 0;
}
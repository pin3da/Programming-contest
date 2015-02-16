using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int mod = 1000000007;
const int MN = 100011;
long long ans[MN];

int main() {
	long long t, n, a, b;
	cin >> t;
	for (int tc = 0; tc < t; ++tc) {
		cin >> n >> a >> b;
		long long mask = a | b;
		cout << __builtin_popcountll(mask) << endl;
	}
  return 0;
}
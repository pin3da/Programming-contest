using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

int main() {
	int t, n, tar;
	cin >> n >> tar;
	string a;
	for (int i = 0; i < n; ++i) {
		cin >> a >> a;
	}
	tar--;
	int i = 0, j = n - 1, turn = 0;
	while ((j - i) >= 1) {
		if (turn == 0) j--;
		else if (turn == 1) i++;
		else {
			int first  = tar - i;
			int second = j - tar;
			if (first < 0 or second < 0) {
				i = -1;
				break;
			}
			if (second > first) {
				j--;
			} else {
				i++;
			}
		}
		turn = (turn + 1) % 3;
	}
	if (i == tar)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
using namespace std;
#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << (x) << endl

const int MN = 1e5 + 100;

int arr[MN];

void add(int j, int &ans, int &inside) {
    if (arr[j - 1]) {
      arr[j - 2] = 1;
    } else {
      arr[j - 1] = 1;
    }
    ans++;
    inside++;
}

int main() {
  int n, k, r;
  cin >> n >> k >> r;
  for (int i = 0; i < k; ++i) {
    int t; cin >> t;
    arr[t - 1] = 1;
  }

  int inside = 0;
  int j = 0, i = 0;
  while (j < r) {
    inside += arr[j++];
  }

  int ans = 0;
  while (j <= n) {
    if (inside < 2) {
      add(j, ans, inside);
      if (inside < 2) {
        add(j, ans, inside);
      }
    }

    inside += arr[j++];
    inside -= arr[i++];

  }
  cout << ans << endl;

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl


int find_best(vector<int> a, vector<int> b) {
  int i = 0;
  int j = 100;
  int best = -1000;
  while (i <= 100 && j >= 0) {
    if (a[i] == 0) {
      ++i; continue;
    }
    if (b[j] == 0) {
      --j; continue;
    }
    best = max(i + j, best);
    if (a[i] < b[j]) {
      b[j] -= a[i];
      i++;
    } else if (a[i] > b[j]) {
      a[i] -= b[j];
      j--;
    } else {
      i++;
      j--;
    }
  }
  return best;
}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<int> a(101), b(101);
    int x, y;
    while (n--) {
      cin >> x >> y;
      a[x]++;
      b[y]++;
      cout << find_best(a, b) << endl;
    }
  }
  return 0;
}

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int first;

void mp(int n) {
  if (!first) printf(",");
  printf("%3d", n);
  first = false;
}

void solve(int n, int m, int k) {
  vector<int> a(n);
  first = true;
  for (int i = 0; i < n; ++i) a[i] = i + 1;
  int i = 0, j = n - 1;
  int f, s;
  while (a.size() > 1) {
    i = (i + a.size()) % a.size();
    j = (j + a.size()) % a.size();
    int ni = i + (m % a.size()) - 1;
    int nj = j - (k % a.size()) + 1;
    ni = (ni + a.size()) % a.size();
    nj = (nj + a.size()) % a.size();
    mp(a[ni]);
    if (ni != nj)
      // mp(a[nj]);
      printf("%3d", a[nj]);
    a.erase(a.begin() + ni);
    i = ni;
    j = nj - 1;
    if (ni == nj) continue;
    if (ni < nj) {
      nj--;
      j--;
    } else {
      i--;
    }
    a.erase(a.begin() + nj);
  }

  if (a.size())
    mp(a[0]);
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m, k;
  while (cin >> n >> m >> k && (n + m + k)) {
    solve(n, m, k);
    puts("");
  }
  return 0;
}

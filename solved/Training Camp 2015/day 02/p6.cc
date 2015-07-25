using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

const int MN = 100001;
int p[MN];

int find_set(int x) {
  return (p[x] == x) ? x : p[x] = find_set(p[x]);
}

void join(int x, int y) {
  p[find_set(x)] = find_set(y);
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  long long n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }

  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  set<long long> seen;
  sort(a.rbegin(), a.rend());

  for (int i = 0; i < n; ++i) {
    if (seen.count(a[i] * k) == 0) {
      seen.insert(a[i]);
    }
  }

  cout << seen.size() << endl;

  return 0;
}

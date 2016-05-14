#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    vector<string> name(n);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> name[i];
      cin >> a[i].first;
      a[i].second = i;
    }

    int cur = 0, k = a[0].first, kr = a[0].first;
    while (a.size() > 1) {
      k = (a.size() == n ? kr : kr - 1) % a.size();
      if (k < 0) k += a.size();
      if (kr & 1)
        cur = (cur + k) % a.size();
      else
        cur = (cur + a.size() - k) % a.size();
      kr = a[cur].first;
      a.erase(a.begin() + cur);
      if ((kr & 1) == 0)
        cur = (cur + a.size() - 1) % a.size();
    }
    cout << "Vencedor(a): " << name[a[0].second] << endl;
  }
  return 0;
}

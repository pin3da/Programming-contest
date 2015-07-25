using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
//#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<int> a(n);
    map<int, int> frec;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      frec[a[i] - i]++;
    }

    int bf = 0, best;
    for (map<int, int>::iterator it = frec.begin(); it != frec.end(); ++it) {
      if (it->second > bf) {
        best = it->first;
        bf = it->second;
      }
    }

    long long cost = 0;
    for (int i = 0; i < n; ++i) {
      if ((a[i] - i) != best) cost++;
    }

    cout << cost << endl;
    for (int i = 0; i < n; ++i) {
      if (i) cout << " ";
      cout << a[i] - (a[i] - i) + best;
    }
    cout << endl;

  }

  return 0;
}

#include<bits/stdc++.h>
using namespace std;

void simulate(vector<int> &a) {
  int best = 100000000;
  int id = -1;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] < best) {
      best = a[i];
      id = i;
    }
  }
  assert(id >= 0);

  a[id] *= -1;
  int j = (id + a.size() - 1) % a.size();
  a[j] = a[j] - a[id];
  j = (id + 1) % a.size();
  a[j] = a[j] - a[id];
}


bool allp(vector<int> &a) {
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] < 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  int tid = 1;
  while (tc--) {
    vector<int> a(5);
    for (int i = 0; i < 5; ++i)
      cin >> a[i];

    while (!allp(a)) {
      simulate(a);
    }

    cout << "Pentagon #" << (tid++) << ":" << endl;
    for (int i = 0; i < a.size(); ++i) {
      if (i) cout << " ";
      cout << a[i];
    }
    cout << endl;
  }
  return 0;
}

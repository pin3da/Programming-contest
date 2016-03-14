#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

typedef bitset<1001> mask;

void solve() {
  string A;
  cin >> A;
  int m; cin >> m;

  vector<string> B(m);
  mask target;
  for (int i = 0; i < m; ++i) {
    cin >> B[i];
    int ok = true;
    for (int j = 0; j < A.size(); ++j) {
      if (B[i].find(A[j]) == string::npos)
        ok = false;
    }
    if (ok)
      target.set(i);
  }

  //D(target);


  for (char i = 'A'; i <= 'Z'; ++i) {
    mask cur;
    for (int j = 0; j < m; ++j) {
      if (B[j].find(i) != string::npos) {
        cur.set(j);
      }
    }
    if ((target ^ cur).count() == 0) {
      cout << i << endl;
      return;
    }
  }
  cout << "No Solution" << endl;

}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t; cin >> t;
  while( t-- ) {
    solve();
  }
}

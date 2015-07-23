using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> a(3);
  int possible = true;
  for (int i = 0; i < n && possible; ++i) {
    int t;
    cin >> t;
    if (t == 25)
      a[0]++;
    else if (t == 50) {
      if (a[0] > 0) {
        a[0]--;
        a[1]++;
      }
      else {
        possible = 0;
      }
    } else {
      if (a[1] > 0) {
        if (a[0] > 0) {
          a[0]--;
          a[1]--;
          a[2]++;
        } else {
          possible = 0;
        }
      } else if (a[0] > 2) {
        a[0] -= 3;
        a[2]++;
      } else {
        possible = 0;
      }
    }
  }

  cout << ((possible) ? "YES" : "NO") << endl;
  return 0;
}

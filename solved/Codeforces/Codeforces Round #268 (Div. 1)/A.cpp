// http://codeforces.com/contest/468/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl


int main () { ___


  int n;cin>>n;

  if (n < 4 )
    cout << "NO" << endl;

  if (n == 4) {
    cout << "YES" << endl;
    cout << "4 * 3 = 12" << endl;
    cout << "12 * 2 = 24" << endl;
    cout << "24 * 1 = 24" << endl;
  }

  if (n == 5) {
    cout << "YES" << endl;
    cout << "5 * 4 = 20" << endl;
    cout << "20 + 3 = 23" << endl;
    cout << "23 + 2 = 25" << endl;
    cout << "25 - 1 = 24" << endl;
  }

  if (n > 5) {
    cout << "YES" << endl;
    cout << "2 - 3 = -1" << endl;
    cout << "-1 + 1 = 0" << endl;
    cout << "0 * 5 = 0" << endl;
    for (int i = 7; i <= n; ++i) {
      cout << "0 * " << i << " = 0" << endl;
    }
    cout << "6 * 4 = 24" << endl;
    cout << "24 + 0 = 24" << endl;
  }
  return 0;

}
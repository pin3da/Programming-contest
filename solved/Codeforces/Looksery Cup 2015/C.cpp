// http://codeforces.com/contest/549/problem/C

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x)  << endl
#define endl '\n'


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  int odd = 0, even = 0, tmp;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    if (tmp & 1)
      odd++;
    else
      even++;
  }

  int p = n - k;
  int t1 = (p + 1) / 2;
  int t2 = p / 2;
  if (p <= 0)
    if (odd & 1)
      cout << "Stannis" << endl;
    else
      cout << "Daenerys" << endl;
  else
    if (t2 >= odd)
      cout << "Daenerys" << endl;
    else
      if (t1 > t2)
        if (t2 - even >= 0)
          if (k & 1)
            cout << "Stannis" << endl;
          else
            cout << "Daenerys" << endl;
        else
          cout << "Stannis" << endl;
      else
        if (t1 - even < 0)
          cout << "Daenerys" << endl;
        else
          if (k & 1)
            cout << "Stannis" << endl;
          else
            cout << "Daenerys" << endl;

  return 0;
}
    cout << "Daenerys" << endl;
        }
      }
    }
  }
  return 0;
}

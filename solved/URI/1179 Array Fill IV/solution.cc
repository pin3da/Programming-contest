#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

void print(vector<int> &a, int p) {
  for (int i = 0; i < a.size(); ++i) {
    if (p) cout << "par[";
    else   cout << "impar[";
    cout << i << "] = " << a[i] << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  vector<int> n(15);
  vector<int> par, impar;
  for (auto &i : n) {
    cin >> i;
    if (i & 1) {
      if (impar.size() == 5) {
        print(impar, 0);
        impar.resize(0);
      }
      impar.push_back(i);
    } else {
      if (par.size() == 5) {
        print(par, 1);
        par.resize(0);
      }
      par.push_back(i);
    }
  }
  print(impar, 0);
  print(par, 1);

  return 0;
}

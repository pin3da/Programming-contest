#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

map<int, string> r;

string rrr(int a) {

  auto b = r.upper_bound(a);
  b--;
  int l = b-> first;
  if (l == a)
    return r[a];
  return r[l] + rrr(a - l);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  r[1000] =  "M";
  r[900] = "CM";
  r[500] = "D";
  r[400] = "CD";
  r[100] = "C";
  r[90] = "XC";
  r[50] = "L";
  r[40] = "XL";
  r[10] = "X";
  r[9] = "IX";
  r[5] = "V";
  r[4] = "IV";
  r[1] =  "I";
  int a;
  while (cin >> a)
    cout << rrr(a) << endl;
  return 0;
}

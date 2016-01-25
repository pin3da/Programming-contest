#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
string months[] = {"January", "February", "March", "April",
                    "May", "June", "July", "August", "September", "October",
                    "November", "December"};
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int x;
  cin >> x;
  cout << months[x - 1] << endl;
  return 0;
}

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i)
      if (a[i - 1] > a[i]) {
        cout << "no" << endl;
        return 0;
      }
  }
  
  cout << "yes" << endl;
  
  return 0;
}

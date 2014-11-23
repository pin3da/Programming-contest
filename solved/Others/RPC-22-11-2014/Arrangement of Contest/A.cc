using namespace std;
#include<bits/stdc++.h>

int main() {

  int n;
  cin >> n;
  vector<string> cad(n);
  for (int i = 0; i < n; ++i) {
    cin >> cad[i];
  }

  sort(cad.begin(), cad.end());
  int j = 0;
  for (int i = 0; i < n; ++i) {
    if ((cad[i][0] - 'A') == j)
      j++;
  }

  cout << j << endl;
  return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main() {

  int n, k;
  cin >> n >> k;
  int max_safe = 1;
  int min_break = k;
  for (int i = 0; i < n; ++i) {
    int floor;
    string result;
    cin >> floor >> result;
    if (result == "SAFE")
      max_safe = max(max_safe, floor);
    else
      min_break = min(min_break, floor);
  }

  cout << max_safe + 1 << " " << min_break - 1 << endl;

  return 0;
}

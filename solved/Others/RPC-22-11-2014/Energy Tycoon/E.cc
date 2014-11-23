using namespace std;
#include<bits/stdc++.h>



int main() {
  
  int n;
  cin >> n;
  string line;
  cin >> line;
  
  int one = 0, two = 0;
  long long ans = 0;
  for (int i = 0; i < line.size(); ++i) {
    if (line[i] == '1') {
      if ((one + 1) + 2 * two <= n) {
        one++;
      } else if (two > 0) {
        two--;
        one++;
      }
    } else {
      if (one + (two + 1) * 2 <= n) {
        two++;
      }
    }
    ans += (two + one);
  }  
  cout << ans << endl;
  return 0;
}

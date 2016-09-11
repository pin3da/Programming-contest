#include<bits/stdc++.h>
using namespace std;

int x[3];
bool check(int i, int acc, int t) {
  if (i == 3) return t && acc == 0;
  if (x[i] == 0) return true;
  if (t >= 2 && acc == 0) return true;
  if (check(i + 1, acc + x[i], t + 1)) return true;
  if (check(i + 1, acc - x[i], t + 1)) return true;
  if (check(i + 1, acc, t)) return true;
  return false;
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  while (cin >> x[0] >> x[1] >> x[2]) {
    puts(check(0, 0, 0) ? "S" : "N");    
  }
  return 0;
}

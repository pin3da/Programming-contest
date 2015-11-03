using namespace std;
#include <bits/stdc++.h>


void solve() {

  string name; int courses;
  cin >> name;
  int y1,y2,m1,m2,d1,d2;
  scanf("%d/%d/%d %d/%d/%d", &y1, &m1, &d1, &y2, &m2, &d2);
  cin >> courses;

  cout << name << " ";
  if (y1 >= 2010) {
    cout << "eligible" << endl;
    return;
  }

  if (y2 >= 1991) {
    cout << "eligible" << endl;
    return;
  }

  if (courses < 41)
    cout << "coach petitions" << endl;
  else
    cout << "ineligible" << endl;
}

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}

#include<bits/stdc++.h>

using namespace std;

const int MN = 10000;
const int ME = 20000;
const int T = 30;

int main() {
  srand(time(0));
  cout << T << endl;
  for (int i = 0; i < T; ++i) {
    cout << MN << ' ' << ME << endl;
    for (int j = 0; j < ME; ++j) {
      cout << random() % MN << ' '  << random() % MN << endl;
    }
  }
  return 0;
}

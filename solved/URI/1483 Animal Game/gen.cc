#include <bits/stdc++.h>

using namespace std;

const int MN = 1000001;
const int MM = 1000001;
const int MV = 1000;

int TC = 30000;

int main() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(1, MV);
  cout << fixed << setprecision(2);
  srand(time(0));
  while (TC--) {
    cout << dis(gen) << " " << rand() % MN;
    cout << " " << rand() % MM << endl;
  }
  cout << 0.0 << " " << 0 << " " << 0 << endl;
  return 0;
}

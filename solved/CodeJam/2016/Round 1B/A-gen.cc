#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

string num[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  srand(time(0));
  int tc = 20;
  cout << tc << endl;
  for (int i = 0; i < tc; ++i) {
    string cur;
    for (int j = 0; j < 30; ++j) {
      cur += num[rand() % 10];
    }
    //random_shuffle(cur.begin(), cur.end());
    cout << cur << endl;
  }

  return 0;
}

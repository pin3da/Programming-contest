#include <bits/stdc++.h>

using namespace std;

int to_target(const string& input, const string& ending) {
  int cost = 0;
  int j = 1;
  for (int i = input.size() - 1; i >= 0; i--) {
    if (input[i] == ending[j])
      j--;
    else
      cost++;

    if (j == -1) return cost;
  }

  return 100;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string n;
    cin >> n;
    int best = 100;
    best = min(best, to_target(n, "00"));
    best = min(best, to_target(n, "25"));
    best = min(best, to_target(n, "50"));
    best = min(best, to_target(n, "75"));
    assert(best != 100);
    cout << best << endl;
  }
  return 0;
}
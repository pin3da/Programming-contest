#include<bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int n;
  while(cin >> s >> n) {
    vector<pair<string, double> > players(n);
    double w, we, sum = 0;
    int r, k;
    for(int i = 0; i < n; i++) {
      cin >> players[i].first;
      cin >> r >> w >> we >> k;
      sum += r;
      double newr = r + k * (w - we);
      players[i].second = newr;

    }
    cout << "Tournament: " << s << endl;
    cout << "Number of players: " << n << endl;
    cout << "New ratings:" << endl;
    for(int i = 0; i<  n; i++) {
      cout << players[i].first << " "<< fixed << setprecision(0) << players[i].second << endl;
    }
    cout << "Media Elo: " << setprecision(0) << sum / n<< endl;
  }
  return 0;
}

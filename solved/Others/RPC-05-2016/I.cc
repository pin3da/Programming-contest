#include<bits/stdc++.h>
using namespace std;

int main() {
  int t; cin>> t;
  bool first = false;
  while(t--) {
    if(first) cout << endl;
    int n,m; cin >> n >> m;
    vector<double> nums(n);
    double sum = 0;
    vector<pair<long long, int> > votes(n);
    double x;
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++)
        cin >> nums[j];
      cin >> x;
      for(int j = 0; j < n; j++) {

        votes[j].first += round(x * (nums[j] / 100.0));
        votes[j].second = j;
      }

      sum += x;
    }
    sort(votes.rbegin(), votes.rend());

    double porc = (100.0 * votes[0].first) / (sum * 1.0);
    //cout << porc << endl;
    if(porc >= 50.1) {
      cout << votes[0].second + 1 << " " << votes[0].first << endl;
    }else{
      if(votes[0].first > votes[1].first) {
        cout << votes[0].second + 1 << " " << votes[0].first << endl;
        cout << votes[1].second + 1 << " " << votes[1].first << endl;
      }else {
        if(votes[0].second < votes[1].second){
          cout << votes[0].second + 1 << " " << votes[0].first << endl;
        cout << votes[1].second + 1 << " " << votes[1].first << endl;
        }else{
          cout << votes[1].second + 1 << " " << votes[1].first << endl;
        cout << votes[0].second + 1 << " " << votes[0].first << endl;
        }
      }
    }
    first = true;
  }
}

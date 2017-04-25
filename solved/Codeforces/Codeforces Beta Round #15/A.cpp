// http://codeforces.com/contest/15/problem/A

using namespace std;
#include<algorithm>
#include<iostream>
#include<queue>

typedef pair<int,int> house;

int main() {

  int n, t;
  cin>>n>>t;

  vector<house> h(n);
  for (int i = 0; i < n; ++i) {
    cin>>h[i].first>>h[i].second;
  }

  sort(h.begin(), h.end());

  int ans = 2;
  for (int i = 1 ; i < n; ++i) {
    double free = h[i].first - h[i].second * 0.5;
    free -= h[i - 1].first + h[i - 1].second * 0.5;
    if (free > t) ans += 2;
    else if (free == t) ans++;
  }

  cout<<ans<<endl;
  return 0;
}
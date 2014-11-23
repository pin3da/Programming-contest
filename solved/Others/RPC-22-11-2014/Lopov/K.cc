using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, k;
  cin >> n >> k;
  vector <pair<int, int> > jewellery(n);
  vector <int> bags(k);
  for (int i = 0; i < n; ++i) {
    cin >> jewellery[i].first >> jewellery[i].second;
  }
  
  for (int i = 0; i < k; ++i) 
    cin >> bags[i];
    
  sort(jewellery.begin(), jewellery.end());
  sort(bags.begin(), bags.end());
 
  
  int j = 0;
  priority_queue<int> q;
  long long ans = 0;
  
  
  for (int i = 0; i < k; ++i) {
    while (j < n and jewellery[j].first <= bags[i]) {
      q.push(jewellery[j].second);
      ++j;
    }
    
    if (!q.empty()) {
      ans += q.top();
      q.pop();
    }
  }
  
  cout << ans << endl;
  
  return 0;
}

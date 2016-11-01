#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

#define debug(x) cout << #x << ": " << x << endl

bool check(vector<pair<int,int> > &x) {
  for(int i = 0; i < (int)x.size() - 1; i++) {
    if(x[i].first != x[i + 1].first) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  while(cin >> n) {
    vector<pair<int, int> > nums(n);
    vector<vector<int> > ans;


    for(int i = 0; i < n; i++) {cin >> nums[i].first; nums[i].second = i;}
    sort(nums.rbegin(), nums.rend());
    if(check(nums)) {cout << nums[0].first << endl << 0 << endl; continue;}
    while(true) {
      if(check(nums)) break;
      int last = nums.back().first;
      int j = nums.size() - 1;
      while (j > 1 && nums[j - 1].first == last) --j;

      vector<int> cur;
      if (j == 1) {
        cur.push_back(0);
        cur.push_back(1);
      }
      else if (j == 3) {
        for (int i = 0; i < 3; ++i)
          cur.push_back(i);
      } else {
        for (int i = 0; i < 2; ++i)
          cur.push_back(i);
      }

      vector<int> frec(nums.size());
      for (int i = 0; i < (int)cur.size(); ++i) {
        if (nums[i].first)
          nums[i].first--;
        frec[nums[i].second] = 1;
      }
      ans.push_back(frec);

      sort(nums.rbegin(), nums.rend());
      /*
      for (int i = 0; i < (int)nums.size(); ++i)
        cout << nums[i].first << ' ';
      cout << endl;
      */
    }
    cout << nums[0].first << endl;
    cout << ans.size() << endl;
    for(int i = 0; i < (int)ans.size(); i++) {
      for(int j = 0; j < n; j++) {
        cout << ans[i][j];
      }
      cout << endl;
    }

  }
  return 0;
}

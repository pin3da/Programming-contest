using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl

int nums[22];
int memo[(1<<14) + 10];
const int target = (1<<14) - 1;

set<vector<int> > all;

void gen(vector<int> cur, int used) {
  if (used == 14) {
    all.insert(cur);
    return;
  }

  for (int i = 0; i < 9; ++i) {
    vector<int> tmp = cur;
    tmp[i] += 3;
    gen(tmp, used + 3);
    tmp = cur;
    if (i < 7) {
      for (int j = 0; j < 3; ++j)
        tmp[i + j]++;
      gen(tmp, used + 3);
    }
  }
}



void solve() {

  vector<int> cur(9, 0);
  int t;
  for (int i = 0; i < 14; ++i) {
    cin>>t;
    cur[t - 1]++;
  }
  if (all.count(cur) > 0)
    cout<<"Vulnerable"<<endl;
  else
    cout<<"Immune"<<endl;
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  vector<int> cur(9, 0);
  for (int i = 0; i < 9; ++i) {
    vector<int> tmp = cur;
    tmp[i] += 2;
    gen(tmp, 2);
  }

  int n;cin>>n;
  for (int i = 0; i < n; ++i)
    solve();
  return 0;
}

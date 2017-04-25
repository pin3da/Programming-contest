// http://codeforces.com/contest/437/problem/B

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = " << (x) <<endl
#define endl '\n'

const int MN = 100001;
long long sum[MN];
long long val[MN];

int lower(int x) {
  for (int i = 0; i < 30; ++i)
    if ((x>>i) & 1) return (1<<i);
}

int main() { ___

  for (int i = 1; i < MN; ++i) {
    val[i] = lower(i);
    sum[i] = sum[i - 1] + val[i];
  }
  int n,k;
  cin>>n>>k;

  if (sum[k] < n) {
    cout<<-1<<endl;
    return 0;
  }

  vector<int> ans;

  for (int i = k; i > 0; i--) {
    if (val[i] > n) continue;
    n -= val[i];
    ans.push_back(i);
  }

  cout<<ans.size()<<endl;
  for (int i = 0; i < ans.size(); ++i) {
    if (i) cout<<" ";
    cout<<ans[i];
  }
  cout<<endl;
  return 0;
}
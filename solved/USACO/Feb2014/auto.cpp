using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 222

int cmp1(const string a, const string b) {
  return 0;
}

int main() { ___

  freopen("auto.in","r", stdin);
  freopen("auto.out","w", stdout);

  int words, queries;

  cin>>words>>queries;
  vector<string> dic(words);
  map<string, int> inv;
  for (int i = 0; i < words; ++i){
    cin>>dic[i];
    inv[dic[i]] = i + 1;
  }

  sort(dic.begin(), dic.end());

  for(int i = 0; i < queries; ++i) {
    int k; string cad;
    cin>>k>>cad;
    string cad2 = cad;
    cad2[cad2.size() - 1]++;
    int l = lower_bound(dic.begin(), dic.end(), cad) - dic.begin();
    int u = lower_bound(dic.begin(), dic.end(), cad2) - dic.begin();
    if ((u - l) < k)
      cout<<-1<<endl;
    else
      cout<<inv[dic[l + k - 1]]<<endl;
  }
  return 0;
}

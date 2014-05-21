using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

string tocad(int n) {
  string c;
  while (n) {
    if (n & 1) c.push_back('1');
    else c.push_back('0');
    n>>=1;
  }
  return c;
}

string cad;
int v[10];

int valid (int n) {
  stringstream ss;
  ss<<n;
  string cad = ss.str();
  for (int i = 0; i < cad.size(); ++i)
    if (!v[cad[i] - '0']) return 0;
  return 1;
}

const int MN = 10001;
int dp[MN];

int main() { ___

  int n;
  while(cin>>n and n) {

    vector<int> num(n);
    cad = "";
    stringstream ss;
    for (int i = 0 ; i < n; ++i) {
      cin>>num[i];
      string s = tocad(num[i]);
      ss<<s;
    }

    cad = ss.str();

    for (int i = 0; i < 10; ++i) cin>>v[i];

    dp[cad.size() - 1] = ((cad[cad.size() -1] == '1') and v[1]);
    dp[cad.size()] = 1;

    for (int i =  cad.size() - 2; i >= 0; --i) {
      dp[i] = 0;
      if (cad[i] == '0') continue;
      int acum = 0;
      for (int l = 1; l < cad.size() - i + 1; ++l) {
        acum <<= 1;
        acum += (cad[i + l - 1] == '1');
        if (acum > 1023) break;
        if (valid(acum) and (dp[i + l] != 0)) dp[i] = l;
      }
    }

    int i = 0;
    int ok = 1;
    vector<int> ans;
    while (true) {
      if (i >= cad.size()) break;
      ans.push_back(i+1);
      i += dp[i];
      if (!i) break;
    }
    if (i != cad.size()) cout<<"NO"<<endl;
    else {
      cout<<"YES";
      for (int i = 0; i < ans.size(); ++i)
        cout<<" "<<ans[i];
      cout<<endl;
    }
  }
  return 0;
}

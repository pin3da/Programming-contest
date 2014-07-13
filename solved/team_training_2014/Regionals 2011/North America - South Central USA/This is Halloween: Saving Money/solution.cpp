using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define D(x) cout<< #x " = "<<(x)<<endl
string ggg;

int get_int() {   getline(cin,ggg);  stringstream ss(ggg);   int s;   ss>>s;  return s; }

string fun(long long i, int d) {
  stringstream ss;
  ss<<i;
  string ans;ss>>ans;
  string t(ans.size(), '0');
  for (int j = 0; j < d; ++j)
    t[j] = ans[j];
  return t;
}

long long solve(long long a, long long b, long long c) {
  return  3*c + ((b*c + a*c + a*b + 3*b)<<1);
}

int main() { ___

  int tc = get_int();
  while (tc--) {
    string line;
    getline(cin, line);
    int idx = -1;
    for (int i = 1; i < line.size(); ++i)
      if (line[i] == '\'')
        idx = i;
    string name = line.substr(1, idx - 1);
    string buffer = line.substr(idx + 1);
    stringstream ss(buffer);
    int a,b,c,d;
    ss>>a>>b>>c>>d;
    cout<<"\"The Present "<<name<<" requires "<<fun(solve(a,b,c), d)<<" square frightometers of paper to wrap\""<<endl;

  }

  return 0;
}

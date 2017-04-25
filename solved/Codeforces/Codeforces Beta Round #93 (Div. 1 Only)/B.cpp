// http://codeforces.com/contest/126/problem/B

using namespace std;
#include<bits/stdc++.h>

vector<int> compute_z(const string &s){
  int n = s.size();
  vector<int> z(n,0);
  int l,r;
  r = l = 0;
  for(int i = 1; i < n; ++i){
    if(i > r) {
      l = r = i;
      while(r < n and s[r - l] == s[r])r++;
      z[i] = r - l;r--;
    }else{
      int k = i-l;
      if(z[k] < r - i +1) z[i] = z[k];
      else {
        l = i;
        while(r < n and s[r - l] == s[r])r++;
        z[i] = r - l;r--;
      }
    }
  }
  return z;
}

int main(){

  string line;
  while( cin>>line) {
    vector<int> z = compute_z(line);

    int maxz = 0, res = 0;
    int n = line.size();
    for (int i = 1; i < n; i++) {
      if (z[i] == n-i && maxz >= n-i) { res = n-i; break; }
      maxz = max(maxz, z[i]);
    }
    if(res == 0){
      cout<<"Just a legend"<<'\n';
      continue;
    }
    for(int i = 0; i< res; ++i) cout<<line[i];
    cout<<'\n';
  }
  return 0;
}
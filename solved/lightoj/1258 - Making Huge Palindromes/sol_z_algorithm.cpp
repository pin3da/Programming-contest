using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> comp_z(string s){
  int n = s.size();
  vector<int> z(n,0);
  int l = 0, r = 0;
  for(int i= 1; i < n; ++i){
    if(i > r){
      l = r = i;
      while(r < n and s[r-l] == s[r]) r++;
      z[i] = r - l;r--;
    }else{
      int k = i -l;
      if(z[k] < r - i +1) z[i] = z[k];
      else{
        l = i;
        while(r < n and s[r-l] == s[r]) r++;
        z[i] = r - l;r--;
      }
    }
  }
  return z;
}

int solve(){
  string cad;
  cin>>cad;
  string cad2 = cad;
  reverse(cad2.begin(), cad2.end());
  cad2 += "$";
  cad2 += cad;
  vector<int> z = comp_z(cad2);
  int i = cad.size();
  while(i < cad2.size() and z[i]!= cad2.size() - i)++i;
  return  i -1;
}

int main(){ ___
  int t;cin>>t;
  for(int i = 0; i< t; ++i){
    cout<<"Case "<<(i+1)<<": "<<solve()<<'\n';
  }
  return 0;
}

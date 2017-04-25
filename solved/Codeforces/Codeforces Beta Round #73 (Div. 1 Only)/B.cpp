// http://codeforces.com/contest/87/problem/B

using namespace std;
#include<bits/stdc++.h>

struct type{
  int err;
  int p;
  type():err(0),p(0){}
};

map<string,type> cod;

type parse(string f){
  int d = 0;
  string name;

  for(int i = 0; i < f.size(); ++i)
    if(f[i]!= '&' and f[i]!='*')
      name.push_back(f[i]);

  //cout<<"redefining "<<name<<" like "<<s<<'\n';
  if(cod.count(name)==0){
    type t;
    t.err = 1;
    return t;
  }
  type t = cod[name];
  d = t.p;

  for(int i = 0; i < f.size(); ++i){
    if(f[i]=='&')d--;
    else if(f[i]=='*')d++;
    else name.push_back(f[i]);
  }
  if(d < 0) t.err = 1;
  t.p = d;

  return t;

}

int main(){

  int q;cin>>q;

  cod["void"] = type();

  while(q--){
    string op;cin>>op;
    string f;cin>>f;
    string s;

    if(op == "typedef"){
      cin>>s;
      cod[s] = parse(f);
    }else{

      type tem = parse(f);
      if(tem.err)
        cout<<"errtype"<<'\n';
      else{
        cout<<"void";
        int t = tem.p;
        for(int i =0 ; i < t; ++i)
          cout<<'*';
        cout<<'\n';
      }

    }
  }

  return 0;
}
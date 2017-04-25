// http://codeforces.com/contest/377/problem/B

using namespace std;
#include<bits/stdc++.h>
#define MN 100010

int n,m, p;

struct bug{
  int id,v;
  bug(){}
  bool operator < (const bug &o) const {
    return v > o.v;
  }
};

struct st{
  int h, cost,id;
  st(){}
  bool operator < (const st & o) const {
    if(h == o.h) return id < o.id;
    return h > o.h;
  }
};

bug b[MN];
st s[MN];
int ans[MN];

long long solve(int t){

  set<pair<int,int> > pq;
  int money = p;
  int ps = 0;
  for(int i = 0;i < m; i+=t){
    while(ps < n and s[ps].h >= b[i].v){
      pq.insert(make_pair(s[ps].cost,s[ps].id));
      ps++;
    }
    if(pq.empty()) return false;
    pair<int,int> act = *(pq.begin());
    if(money < act.first) return false;
    pq.erase(pq.begin());
    money -= act.first;
    for(int j = 0; j + i< m and j < t; ++j)
      ans[b[i+j].id] = act.second + 1;
  }
  return true;
}

int main(){
  while(cin>>n>>m>>p){
    for(int i = 0; i< m; ++i){
      cin>>b[i].v;
      b[i].id = i;
    }
    for(int i = 0; i < n; ++i) {
      cin>>s[i].h;
      s[i].id = i;
    }
    for(int i = 0; i < n; ++i)
      cin>>s[i].cost;

    sort(b,b+m);
    sort(s,s+n);

    if(!solve(m)){
      cout<<"NO"<<endl;
      return 0;
    }
    int lo = 1, hi = m;
    while(lo < hi){
      int mid = (lo + hi)>>1;
      if(solve(mid)) hi = mid;
      else lo = mid + 1;
    }

    solve(lo);
    cout<<"YES"<<endl;
    for(int i = 0; i< m ; ++i){
      if(i) cout<<" ";
      cout<<ans[i];
    }
    cout<<endl;

  }
  return 0;
}
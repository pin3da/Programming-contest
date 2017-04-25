// http://codeforces.com/contest/404/problem/C

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 1000001


int d[MN];

int main() { ___

  int n, k;
  cin>>n>>k;

  For(i,n) cin>>d[i];

  int node = -1;
  For (i,n) {
    if (d[i] == 0) {
      if (node != -1) {
        cout<<-1<<endl;
        return 0;
      }
      node = i;
    }
  }
  if (node == -1) {
    cout<<-1<<endl;
    return 0;
  }

  vector<pair<int,int> > data(n);
  vector<int> ned(n,0);
  For(i,n) data[i] = make_pair(d[i],i);
  sort(data.begin(), data.end());
  map<int, vector<int> > dist;
  dist[0].push_back(data[0].second);
  int id = 1;
  vector<pair<int,int> > ans;
  while(id < n) {
    pair<int,int> act = data[id];
    //D(id);
    //D(act.first);
    if(dist.count(act.first - 1) == 0 or dist[act.first - 1].size() == 0) {
      //cout<<"No edges from dist "<<act.first-1<<endl;
      cout<<-1<<endl;
      return 0;
    }
    ans.push_back(make_pair(act.second, dist[act.first - 1].back()));
    //D( dist[act.first - 1].back());
    ned[dist[act.first - 1].back()]++;
    ned[act.second]++;
    if (ned[dist[act.first - 1].back()] >= k) {
      //cout<<"Max numed reached by "<<dist[act.first - 1].back()<<endl;
      dist[act.first - 1].pop_back();
    }
    if (ned[act.second] > k) {
      //cout<<"Too many edges for vertex "<<act.second<<endl;
      cout<<-1<<endl;
      return 0;
    }
    if(ned[act.second] < k)
      dist[act.first].push_back(act.second);
    id++;
  }

  cout<<ans.size()<<endl;
  For(i,ans.size()){
    cout<<(ans[i].first+1)<<" "<<(ans[i].second+1)<<endl;
  }


  return 0;
}
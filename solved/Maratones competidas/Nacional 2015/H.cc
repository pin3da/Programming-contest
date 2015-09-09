// Sol by @carlos4rias
#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int nc = 0;
  while( getline(cin,s) ){
    if(nc) cout << "*" << endl;
    nc = 1;
    vector<int > num;
    vector<pair<int,int > > nodos;
    set<int> iniciales;
    priority_queue<int,vector<int>, greater<int> > Q;
    stringstream ss; ss << s;
    int x,maxn = -1,idx = 0;


    while( ss >> x){
      maxn = max(maxn,x);
      num.push_back(x);
      nodos.push_back(make_pair(x,idx++));
      iniciales.insert(x);
    }

    sort(nodos.begin(), nodos.end());

    if(maxn >= num.size() + 2){
      cout << "impossible" << endl;
      continue;
    }

    vector<int> G[num.size() +2];

    for(int i = 0; i < num.size() + 2; i++){
      if(iniciales.count(i))continue;
      Q.push(i);
    }


    for(int i = 0; i < num.size(); i++){
      int cur = Q.top();Q.pop();
      //cout << "Cur: " << cur << endl;
      G[num[i]].push_back(cur);
      G[cur].push_back(num[i]);

      vector<pair<int,int> >::iterator it = lower_bound(nodos.begin(), nodos.end(), make_pair(num[i],i+1));

      if(it == nodos.end() || it->first != num[i]){
        //cout << "entra: " << num[i] << endl;
        Q.push(num[i]);
      }

    }

    int s1 = Q.top(); Q.pop();
    int s2 = Q.top(); Q.pop();
    G[s1].push_back(s2);
    G[s2].push_back(s1);

    cout << num.size() + 2 << endl;

    for(int i = 0; i < num.size() + 2; i++){
      sort(G[i].begin(),G[i].end());
      for(int j = 0; j < G[i].size(); j++){
        if(j) cout << " ";
        cout << G[i][j];
      }
      cout << endl;
    }

  }
}

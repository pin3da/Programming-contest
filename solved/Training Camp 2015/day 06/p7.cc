using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

template<class T>
string tos(T t){stringstream ss; ss<<t; string r;ss>>r;return r;}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string c;
  while(cin>>c){
    vector<string> pre;
    bool ok = 0;
    for(int i=0; i*8 < 1000; i++)
      pre.push_back(tos(i*8));

    // sort(c.begin(),c.end());
    for(int i=0; i < pre.size();i++){
      int j=0,k=0;
      while(j< c.size() && k < pre[i].size()){
        if(c[j] == pre[i][k]){
          k++;
        }
        j++;
      }
      if(k==pre[i].size()){
        cout<<"YES"<<endl<<pre[i]<<endl;
        ok = 1;
        break;
      }

    }
    if(!ok)
      cout<<"NO"<<endl;
  }
  return 0;
}

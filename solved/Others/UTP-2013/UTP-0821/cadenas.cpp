using namespace std;
#include<bits/stdc++.h>
#define For(i,n) for(int i = 0; i< (n); ++i)
#define foreach(it,n) for(typeof ((n).begin()) it = n.begin();  it != (n).end(); ++it )
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) x.begin(),x.end()


class FenwickTree{
  vector<long long> v;
  int maxSize;

public:
  FenwickTree(int _maxSize) : maxSize(_maxSize+1) {
    v = vector<long long>(maxSize, 0LL);
  }

  void add(int where, long long what){
    for (where++; where <= maxSize; where += where & -where){
      v[where] += what;
    }
  }

  long long query(int where){
    long long sum = v[0];
    for (where++; where > 0; where -= where & -where){
      sum += v[where];
    }
    return sum;
  }

  long long query(int from, int to){
    return query(to) - query(from-1);
  }

};

int main(){
    
    string cad;
    string comienza;
    string termina;
    cin>>cad>>comienza>>termina;
    FenwickTree tree(cad.size()+10);
    
    For(i,cad.size()-termina.size()){
        if(cad.substr(i,termina.size()) == termina)
            tree.add(i,1);
    }
    long long ans = 0;
    For(i,cad.size() - comienza.size()){
        if(cad.substr(i,comienza.size()) == comienza){
            ans += tree.query(i,cad.size());
        }
    }

    cout<<ans<<endl;
    
    return 0;
}

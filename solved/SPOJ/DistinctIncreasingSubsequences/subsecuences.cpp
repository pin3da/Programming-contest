using namespace std;
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#define D(x) cout<< #x " = "<<(x)<<endl

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
    long long fact = v[0];
    for (where++; where > 0; where -= where & -where){
      fact += v[where];
    }
    return fact;
  }

  long long query(int from, int to){
    if(from == 0) return query(to);
    return query(to) - query(from-1);
  }

};



const long long modulo = 5000000;

const int N = 30;
long long choose[N+1][N+1];
int main(){

/* Binomial coefficients */
for (int i=0; i<=N; ++i) choose[i][0] = choose[i][i] = 1;
for (int i=1; i<=N; ++i)
for (int j=1; j<i; ++j)
choose[i][j] = choose[i-1][j-1] + choose[i-1][j];


    int n,k;
    cin>>n>>k;    
    vector<long long> data(n);
    for(int i = 0; i< n; ++i)
        cin>>data[i];
  
    vector<long long> val = data;
    map<long long,int > cod;
    sort(data.begin(),data.end());
    for(int i = 0; i< n; ++i) cod[data[i]] = i;
    
    FenwickTree tree(n+10);
    reverse(val.begin(),val.end());
    long long ans = 0;
    for(int i = 0; i< n; ++i){
        if(tree.query(cod[val[i]],cod[val[i]])) continue;
        long long greater = tree.query(cod[val[i]],n-1);
        if(greater + 1 >= k){
            long long t = choose[greater][k];
            D(t);
            ans += t;
            ans %= modulo;
        }
            tree.add(cod[val[i]],1);
    }
    
    cout<<ans<<endl;
    
    return 0;
}


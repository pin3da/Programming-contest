using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000


class FenwickTree{

    int maxSize;

    public:
    vector<long long> v;
    
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
            sum |= v[where];
        }
        return sum;
    }

    long long query(int from, int to){
        return query(to) - query(from-1);
    }

};

int main(){


    int n;cin>>n;
    FenwickTree tree(n);
    int k;
    For(i,n){
        cin>>k;
        tree.add(i,k);
    }
    set<int> ans;
    int super=0;
    for(int i=0;i<n;++i){
        for(int j=1;j<=i;++j){
            int t = tree.query(j,i);
            if(t<0)continue;
            D(t);
            if(ans.count(t)<1){
                ans.insert(t);
                super++;
            }
         }
    }
    cout<<super<<endl;
}

using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>

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

const double pi=acos(-1);

struct point{
	int x,y;
	point() {}
	point(int X, int Y) : x(X), y(Y) {}
};

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
    string cad;cin>>cad;
    
	return 0;
}

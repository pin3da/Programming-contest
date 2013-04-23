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
#include<cctype>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
const double Pi2=acos(0);
typedef long long int lli;
typedef pair<int , int> pii;


int main(){
    int len,k;cin>>len>>k;
    string cad;cin>>cad;
    map<string,string> nnext;
    string original = cad;
    while(nnext.count(cad)==0){
        string cad2 = cad;
        int index = cad2.find("47");
        if(index == string::npos)break;
        if(index%2==0)
            cad2[index] = cad2[index+1] = '4';
        else
            cad2[index] = cad2[index+1] = '7';
        nnext[cad]=cad2;
        cad =  cad2;
    }
    k %= nnext.size();
    while(k--){
        original = nnext[original];
    }
    cout<<original<<endl;
}

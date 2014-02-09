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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
const double Pi2=acos(0);
typedef long long int lli;
typedef pair<int , int> pii;

string ss(string cad){
    string t = cad.substr(0,2);
    string h = cad.substr(2,4);
    return h+t;
}


int main(){
    string colors;cin>>colors;
    sort(all(colors));
    set<string> ans;
    do{ 
       // D(colors);
        string otro = colors;
        sort(otro.begin(),otro.begin()+2);
        sort(otro.begin()+2,otro.begin()+4);
        sort(otro.begin()+4,otro.end());
        string otro2 = ss(otro);
        int ff = 0;
        while(otro!=otro2){
            ff |= ans.count(otro2);
            otro2 = ss(otro2);
        }
        if(!ff)
            ans.insert(colors);
    }while(next_permutation(all(colors)));
    cout<<ans.size()<<endl;
}

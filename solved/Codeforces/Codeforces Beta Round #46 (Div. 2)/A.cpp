// http://codeforces.com/contest/49/problem/A

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


int isvoc(char a){
    return a=='a' or a=='e' or a=='i' or a=='o' or a=='u' or a=='y';
}
int main(){
    string cad;
    getline(cin,cad);
    For(i,cad.size()) cad[i] = tolower(cad[i]);
    stringstream ss(cad);
    string otro;
    string total="";
    while(ss>>otro){
        total+=otro;
    }
    cout<<((isvoc(total[total.size()-2]))?"YES":"NO")<<endl;
}
// http://codeforces.com/contest/47/problem/B

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


string m[3];

int check(string mio){
    map<char,int> pos;
    For(i,3){
        pos[mio[i]]=i;
    }
    For(j,3){
        if(m[j][1]=='<'){
            if(pos[m[j][0]] >= pos[m[j][2]]) return 0;
        }else{
            if(pos[m[j][0]] <= pos[m[j][2]]) return 0;
        }
    }
    return true;

}

int main(){
    
    cin>>m[0]>>m[1]>>m[2];
    string mio = "ABC";
    do{
        if(check(mio)){
            cout<<mio<<endl;
            return 0;
        }
    }while(next_permutation(all(mio)));
    
    cout<<"Impossible"<<endl;
    
    return 0;
}
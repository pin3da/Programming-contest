// http://codeforces.com/contest/99/problem/A

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




int main(){
    string num;
    cin>>num;
    int i=0;
    char last;
    while(num[i]!='.' and i<num.size()){
        last = num[i];
        ++i;
    }  
    if(last=='9')
        cout<<"GOTO Vasilisa."<<endl;
    else{
        int j=i+1;
        if(num[j]>='5'){
            For(m,i-1){
                cout<<num[m];
            }
            cout<<((char)(num[i-1]+1))<<endl;
        }else{
            For(m,i){
                cout<<num[m];
            }
            cout<<endl;
        }
        
    }

}
// http://codeforces.com/contest/30/problem/A

using namespace std;
#include<iostream>
#include<sstream>
#include<map>
#include<string>
#include<cmath>


template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }


int main(){
    long long a,b,c;
    while(cin>>a>>b>>c){
//        long long d = ceil(sqrt()
        long long d = fabs(b);
        for(long long i = -(d*10) ; i<=(d*10) ;++i){
            if(round(a*pow(i,c)) == b){
                cout<<i<<endl;
                return 0;
            }
        }
    }
    cout<<"No solution"<<endl;
    return 0;

}
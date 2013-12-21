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
    long double a,b,c;
    while(cin>>a>>b>>c){
        long double iz = b/(long double)a;
        long double der = pow(iz, 1/(long double)c);
        long double m1 = ceil(der);
        long double m2 = floor(der);
        if(pow(m1,c) == der){
            cout<<m1<<endl;
        }else if(pow(m2,c) == der){
            cout<<m2<<endl;
        }else{
            cout<<"No solution"<<endl;
        }
    }

    return 0;

}

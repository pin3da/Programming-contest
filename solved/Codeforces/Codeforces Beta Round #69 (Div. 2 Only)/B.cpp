// http://codeforces.com/contest/80/problem/B

using namespace std;
#include<iostream>
#include<sstream>
#include<map>
#include<string>


template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }


int main(){
    double angle_min = 360.0/60.0;
    double angle_hour = 360.0/12.0;
    string tmp;
    getline(cin,tmp,':');
    int horas =  toInt(tmp);
    getline(cin,tmp);
    int minutos = toInt(tmp);
    double ansmin = 0,anshour = 0;
    if(horas >= 12){
//        anshour += 12.0*angle_hour;
        horas -= 12;
    }
    anshour += horas*angle_hour;
    anshour += (minutos/60.0)*angle_hour;
    ansmin += minutos*angle_min;
    
    cout<<anshour<<" "<<ansmin<<endl;
    return 0;

}
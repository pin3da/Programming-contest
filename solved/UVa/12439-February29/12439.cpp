/*
http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3870
Manuel Pineda
Accepted, 0.012s
*/

using namespace std;
#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#define F 93


int date(string month,int day){
    int d;
    if(month=="January")d=1;    
    if(month=="February")d=2;
    if(month=="March")d=3;
    if(month=="April")d=4;
    if(month=="May")d=5;
    if(month=="June")d=6;
    if(month=="July")d=7;
    if(month=="August")d=8;
    if(month=="September")d=9;
    if(month=="October")d=10;
    if(month=="November")d=11;
    if(month=="December")d=12;
    return (d*32)+day;
}

int main(){
    int numcas,day,day2,year,year2,cont=0;
    int date1,date2,res,a;
    string f1,f2;
    cin>>numcas;
    while(numcas--){
        a=0;
        cin>>f1;
        scanf("%d, %d",&day,&year);
        cin>>f2;
        scanf("%d, %d",&day2,&year2);
        date1=date(f1,day);
        date2=date(f2,day2);
        if(date1<=F)year--;
        if(date2<F)year2--;
        a = year2/4;
        a -= year2/100;
        a += year2/400;
        res = year/4;
        res -= year/100;
        res += year/400;
        a-=res;
        cout<<"Case "<<++cont<<": "<<a<<endl; 
    }
    return 0;    
}

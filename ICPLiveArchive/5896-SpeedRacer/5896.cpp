/*
Manuel Pineda
No accepted yet
*/
using namespace std;
#include<iostream>
#include<cstdio>
#include<string>
#include<cctype>
#include<cmath>
#define Mdouble 1e+7

const double EPS = 1e-6;
char buf[20];

int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

double a,b,c,d,m,t,p;

double fun(double v){
    return v*v*v*a + v*v*b + c*v;
}

void remceros(char *cad) {
    int n=0 ;while(cad[n]!='\0')n++;
    int i=n-1;
    while (cad[i]=='0' && cad[i-1]!='.') {
        cad[i] = '\0';
        i--;
    }    
}

int main (){
	int i;
	double si,un,f,e,mid,ans;
    while(cin>>a>>b>>c>>d>>m>>t){
        p=(t/m)-d;
		si=0.0;
		un= Mdouble;
        while(cmp(si,un)==-1){
			f=fun(si);
			e=fun(un);
			mid=fun((si+un)/2.0);
			if(cmp(mid,p)==-1)
				si=(si+un)/2.0;
			else if(cmp(mid,p)==1)
				un=(si+un)/2.0;
			else{
				ans=(si+un)/2.0;
				break;
			}			
		}
		ans=((int)(ans*100.0))/100.0;
		sprintf(buf,"%lf",ans);
        remceros(buf);
        printf("%s\n",buf);
    }
    return 0;    
}

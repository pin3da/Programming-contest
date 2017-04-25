// http://codeforces.com/contest/215/problem/A

using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define For(i,a) for(int i=0;i<a;++i)
#define D(x) cout<< #x " "<<x<<endl;

bool isInt(int a,int b){
	double c= a/(double)b;
	int d= a/b;
	return (fabs(c-d)==0)?1:0;
}


int main(){
	int t,n,m;cin>>n;
	int a[n];
	For(i,n)
		cin>>a[i];
	cin>>m;
	int b[m];
	For(i,m)
		cin>>b[i];
	
	int c[m*n];
	int cont=0;
	For(i,n)
		For(j,m)
			c[cont++]= ((isInt(b[j],a[i]))?(b[j]/a[i]):0);
	sort(c,c+m*n);
	reverse(c,c+m*n);
	int ant= c[0];
	cont=0;
	For(i,m*n){
//		D(c[i]);
		if(c[i]==ant)
			cont++;
		else
			break;
	}
	cout<<cont<<endl;
}

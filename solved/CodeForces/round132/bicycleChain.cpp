using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define For(i,a) for(int i=0;i<a;++i)
#define D(x) cout<< #x " "<<x<<endl;

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
			c[cont++]= ((b[j]%a[i]==0)?(b[j]/a[i]):0);
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

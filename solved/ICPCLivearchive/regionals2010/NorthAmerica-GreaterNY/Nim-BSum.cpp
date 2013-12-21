/**
* Manuel Pineda
*/
using namespace std;
#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#define all(x) x.begin(),x.end()
#define D(x) cout<< #x " = "<<(x)<<endl

/**
* Simulación
*/

int solve(int b,int x,int y){
	int ans = 0;
	int a[1000000];
	int index=0;
	while((x!=0) or (y!=0)){
		int d1 = x%b;
		int d2 = y%b;
		x/=b;
		y/=b;
		int da = (d1+d2)%b;
		a[index++]=da;
	}
	while(index--){
		ans*=b;
		ans+=a[index];
	}
	
	return ans;

}

int main(){
	int numc,cas;cin>>numc;
	int base;
	int n1,n2;
	while(numc--){
		cin>>cas>>base>>n1>>n2;
		cout<<cas<<" "<<solve(base,n1,n2)<<endl;
	}
	return 0;
}


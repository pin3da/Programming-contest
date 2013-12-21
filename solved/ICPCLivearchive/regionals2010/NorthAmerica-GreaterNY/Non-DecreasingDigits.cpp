/**
* Manuel Pineda
*/
using namespace std;
#include<iostream>
#include<map>
#include<string>
#include<cstring>

typedef long long int lli;

// Estructura para hacer memorizacion.
lli dp[70][15];


/**
* La idea es contar cuantos numeros existen de longitud a
* con numeros crecientes, mayores o iguales a b.
* Para esto podemos hacer una funcion que intente "poner"
* todos los números (i) mayores o iguales a b.
* Con esta idea, vemos que ahora tenemos que solucionar un subproblema
* contar para una longitud a - 1 y todos los números mayores o iguales a i.
* El caso base es cuando la longitud es 1 en cuyo caso la solución es 1.
*/

lli solve(int a,int b){
	if(dp[a][b]!=-1) return dp[a][b];
	
	if(a==1) return dp[a][b] = 1LL;
	lli ans = 0;
	for(int i=b;i<=9;++i){
		ans += solve(a-1,i);
	}
	return dp[a][b] = ans;

}



int main(){
	int c;cin>>c;
	while(c--){
		int k;cin>>k;
		int a;cin>>a;
		memset(dp,-1,sizeof(dp));
		cout<<k<<" "<<solve(a+1,0)<<endl;
	
	}

	return 0;
}

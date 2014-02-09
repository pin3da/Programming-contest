using namespace std;
#include<iostream>

long mod;

int ** mult(int **a, int **b) {
	int **m1;
	m1= new int *[2];
   	for (int i = 0; i < 2; i++)
		m1[i]= new int [2];

   	for (int i = 0; i < 2; i++)
    	for (int j = 0; j < 2; j++)
         	for (int k = 0; k < 2; k++)
            	m1[i][j] = ((m1[i][j] + ((a[i][k] % mod) * (b[k][j] % mod))) % mod);
    return m1;
}

int ** bigModMatriz(int **a, long exp) {
	int **m1;
	m1= new int *[2];
   	for (int i = 0; i < 2; i++)
		m1[i]= new int [2];
   	m1[0][0]=1;
	m1[1][1]=1;
    while (exp > 0) {
        if (exp % 2 == 1)
            m1 = mult(m1, a);
        a = mult(a, a);
        exp >>= 1;
    }
    return m1;
}

int main(){
	long n,m;
	int **fib;//[2][2]={0,1,1,1};	
	fib= new int *[2];
   	for (int i = 0; i < 2; i++)
		fib[i]= new int [2];

	for (int i = 0; i < 2; i++)
    	for (int j = 0; j < 2; j++)
			fib[i][j]=1;
	fib[0][0]=0;
	
	while(cin>>n){
		cin>>m;
		mod = 1<<m;
		cout<<bigModMatriz(fib,n+1)[0][0]%mod<<endl;
	}
	return 0;
}

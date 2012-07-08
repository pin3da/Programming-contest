/*
Manuel Pineda
*/

using namespace std;
#include<iostream>

int main(){
	int numcas;cin>>numcas;
	int total;
	while(numcas--){
		cin>>total;
		int mio = total/2;
		cout<<mio<<" "<<total-mio<<endl;
	}
	return 0;
}

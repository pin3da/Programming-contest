/*
http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3834

Manuel Pineda,
accepted - 0.008

*/

using namespace std;
#include<iostream>
#include<cstdio>
#include<sstream>
#include<string>

int main(){
	string cad;
	string op;
	long long sum=0,t=0;
	int numcas;scanf("%d\n",&numcas);
	while(numcas--){
		getline(cin,cad);
		stringstream ss(cad);
		ss>>op;
		if(op=="donate"){
			ss>>t;
			sum+=t;
		}else if(op == "report")
			cout<<sum<<endl;
		
	}
}

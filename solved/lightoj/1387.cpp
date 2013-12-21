using namespace std;
#include<iostream>
#include<cstdio>
#include<sstream>
#include<string>

int main(){
	string cad;
	string op;
	int T,cas=0;scanf("%d\n",&T);
	while(T--){
		cout<<"Case "<<++cas<<":"<<endl;
		long long sum=0,t=0;
		int numcas;scanf("%d\n",&numcas);
			while(numcas--){
				cin>>op;
				if(op=="donate"){
					cin>>t;
					sum+=t;
				}else if(op == "report")
					cout<<sum<<endl;
			}
	}
}

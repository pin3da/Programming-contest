/**
* Manuel Pineda
*/
using namespace std;
#include<iostream>
#include<map>
#include<string>
#include<cstring>

map<string,int> cod;

/**
* Simulación
*/

int main(){
	cod["TTT"]=0;
	cod["TTH"]=1;
	cod["THT"]=2;
	cod["THH"]=3;
	cod["HTT"]=4;
	cod["HTH"]=5;
	cod["HHT"]=6;		
	cod["HHH"]=7;
	
	int num;cin>>num;
	int dset;
	int sets[8];
	string cad;
	string t;
	while(num--){
		memset(sets,0,sizeof(sets));
		cin>>dset;
		cin>>cad;
		cout<<dset<<" ";
		for(int i=0;i<cad.size()-2;++i){
			string tmp ="";
			for(int j=0;j<3;++j)
				tmp+=cad[i+j];
			sets[cod[tmp]]++;
		}
		for(int i=0;i<8;++i)
			cout<<sets[i]<<((i<7)?" ":"\n");
	
	}

	return 0;
}



// incompleto
using namespace std;
#include<iostream>
#include<vector>
#include<map>

typedef pair<bool,int> problem;
typedef vector<problem> submi;

map<int, submi> usrs;

int main(){
	int numcas;cin>>numcas;
	int usr,pid,time;
	char jud;
	while(numcas--){
		cin>>usr>>pid>>time>>jud;
		int i;
		for(i=0; i< usrs[usr].size();++i){
			if(usrs[usr][i].second == pid){
				
			}
		}
	}
	return 0;
}

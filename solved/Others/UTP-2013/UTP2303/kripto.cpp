using namespace std;
#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<set>
#include<vector>
#define MP 1000001

vector<int> set1(MP);
vector<int> set2(MP);
vector<int>::iterator it;


int main(){
	string men, sent,tmp;
	vector<string> words;
	vector<string> mensaje;
	int pos=0;
	getline(cin, men, '$');
	getline(cin, sent, '$');
	stringstream ss(sent);
	stringstream ss2(men);
	while(ss>>tmp){
	     words.push_back(tmp);
	}
	while(ss2>>tmp){
	     mensaje.push_back(tmp);
	}
	int len1=words.size();
	int len2=mensaje.size();
	int max=1;
	for(int i=0;i<len1;i++){
		set1[i]=max++;
		for(int j=0;j<i;j++){
			if(words[i]==words[j]&& i!=j){
				set1[i]=set1[j];
				max--;
				break;
			}
		}
	}
	for(int i=0;i<len1;i++)
		cout<<set1[i]<<" ";
	cout<<endl;
	max=1;
	for(int i=0;i<len2;i++){
		set2[i]=max++;
		for(int j=0;j<i;j++){
			if(mensaje[i]==mensaje[j]&& i!=j){
				set2[i]=set2[j];
				max--;
				break;
			}
		}
	}
	for(int i=0;i<len2;i++)
		cout<<set2[i]<<" ";
	cout<<endl;
	
	while(it!=set1.end()){
		it = search(set1.begin(),set1.begin()+len1,set2.begin(),set2.begin()+len2);
		for(int i=0;i<len2;i++)
		    set2[i]=set2[i]-1;		
	}
	cout<<int(it-set1.begin())<<endl;
	
    //cout<<*(search (set2, set2+len2, set1, set1+len1));
	

	return 0;	
}




using namespace std;
#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include<cstdio>
#include<cctype>
#include<map>

map<char,int> mp;
typedef pair<int,char> pic;
vector<pic> vec;

int cmp(pic a,pic b){
	if(a.first == b.first)return a.second < b.second;
	return a.first > b.first;
}

int main(){
	string cad;
	char tmp;
	while(getline(cin,cad)){
		for(int i=0;i<cad.size();i++){
        	if(isalpha(cad[i]))
            	cad[i]=toupper(cad[i]);
            else
            	cad[i]=' ';
        }
		stringstream ss(cad);
		while(ss>>tmp)mp[tmp]++;
	}
	map<char,int>::iterator it;
	for(it=mp.begin();it!=mp.end();it++){
		pic tt(it->second,it->first);
		vec.push_back(tt);
	}
	sort(vec.begin(),vec.end(),cmp);
	for(int i=0;i<vec.size();i++){
		cout<<vec[i].second<<" "<<vec[i].first<<endl;
	}
	return 0;
}

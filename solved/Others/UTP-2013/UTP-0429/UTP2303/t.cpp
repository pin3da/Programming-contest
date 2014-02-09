using namespace std;
#include<iostream>
#include<algorithm>
#include<vector>

int main(){
	vector<int> a(4);//={1,2,3,4};
	vector<int>::iterator it;
	for (int i=1; i<5; i++) a[i-1]=i;
	int b[2]={3,2};
	it = search(a.begin(),a.end(),b,b+2);
	cout<<int(it-a.begin())<<endl;
	return 0;
}

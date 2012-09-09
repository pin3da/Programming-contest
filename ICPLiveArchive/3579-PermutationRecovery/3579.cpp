using namespace std;
#include<iostream>
#include<cstring>

int main(){
	int num;
	while(cin>>num && num){
		int array[num];
		memset(array,0,sizeof(array));
		int mio,j;
		for(int i=0;i<num;++i){
			cin>>mio;
			j=0;
			mio++;
			while(mio>0){
				if(!array[j]){
					mio--;
					j++;
				}else{
					j++;
				}
			}			
			array[--j]=i+1;
		}
		for(int i=0;i<num;++i)
			cout<<array[i]<<((i!=num-1)?",":"\n");
	}
	return 0;
}

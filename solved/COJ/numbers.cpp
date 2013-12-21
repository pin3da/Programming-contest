using namespace std;
#include<iostream>
#include<cmath>
#include<cctype>
#include<string>
#include<vector>
#include<algorithm>

#define D(x) cout<< #x " = "<<x<<endl




int gcd(int a,int b){
    int tmp;
    while(b){
        a%=b;
        tmp =a;
        a=b;
        b=tmp;
    }
    return a;
}

int main(){
    int n;
    while(cin>>n){
        vector<int> nums(n);
        for(int i =0;i<n;++i)
            cin>>nums[i];
        int res = 0;
        sort(nums.begin(),nums.end());
		for(int i = n - 1; i >= 0; i--){
			bool bien = true;
			int numero = nums[i];
			for(int j = n - 1; j >= 0; j--)
				if(j != i && gcd(numero, nums[j]) != 1){
					bien = false;
					break;
				}
			if(bien){
				res = numero;
				break;
			}
		}
		cout<<res<<endl;
    }
    return 0;
}







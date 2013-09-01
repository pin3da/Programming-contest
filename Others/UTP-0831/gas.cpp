using namespace std;
#include<bits/stdc++.h>
#define For(i,n) for(int i = 0; i< (n); ++i)
#define D(x) cout<< #x " = "<<(x)<<endl
#define foreach(it,x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)

template<class t>
int to_int(t r){
    stringstream ss;ss<<r;int k;ss>>k;return k;
}

int getpos(string a){
    For(i,a.size()){
        if(a[i]=='-') return i;
    }
    return -1;
}

int main(){
    int tc;cin>>tc;
    For(tid,tc){
        cout<<"Gas Station #"<<tid+1<<":"<<endl;
        int anterior = 199;
        vector<string> in(3);
        For(i,3)cin>>in[i];
        cout<<"   Input:  "<<in[0]<<" "<<in[1]<<" "<<in[2]<<endl;
        For(i,3){
            string &a = in[i];
            int index = getpos(a);
            if(index != -1){
                For(j,10){
                    a[index] = j+'0';
                    if(to_int(a)> anterior)break;
                }
            }
            anterior = to_int(a);
        }
        cout<<"   Output: "<<in[0]<<" "<<in[1]<<" "<<in[2]<<endl;
        cout<<endl;
        
    }


}

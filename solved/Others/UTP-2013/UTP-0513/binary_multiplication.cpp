using namespace std;
#include<iostream>
#include<algorithm>
#include<cstdio>

typedef unsigned long long ll;

ll to_int(string a){
    ll ans = 0;
    int j = 0;
    for(int i = a.size()-1;i>=0; --i){
        ans |= (a[i]=='1')? (1LL<<j):0LL;
        j++;
    }
    return ans;
}

void print_spaces(int t){
    while(t--){
        printf(" ");
    }
}

void print_line(int t){
    while(t--){
        printf("-");
    }
}
void print_zeros(int t){
    while(t--){
        printf("0");
    }
}
string to_str(ll a){
    string ans = "";
    while(a){
       if(a&1) ans = "1" + ans;
       else ans = "0" + ans;
       a>>=1;
    }
    return ans;
}
int main(){
    string a,b;
    int first = 1;
    while(cin>>a>>b and (a!="0" or b!="0")){
        ll aa = to_int(a);
        ll bb =  to_int(b);
        ll c = aa*bb;
        if(!first){
            cout<<endl;
        }else{
            first = 0;
        }
        int ss = 64 - __builtin_clzll(c);
        print_spaces(ss-a.size());
        cout<<a<<endl;
        print_spaces(ss- b.size());
        cout<<b<<endl;
        print_spaces(ss- max(a.size(),b.size()));
        print_line(max(a.size(),b.size()));
        cout<<endl;
        for(int i = 0; i < b.size(); ++i){
            print_spaces(ss - a.size() - i);
            if(b[b.size()-1-i] == '1'){
                cout<<a<<endl;
            }else{
                print_zeros(a.size());
                cout<<endl;
            }
        }

        print_line(ss);
        cout<<endl;
//        cout<<ss<<endl;
        cout<<to_str(c)<<endl;
        
    }
    return 0;
}

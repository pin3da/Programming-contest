/**
*  UTP BMO
*/
using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl
#define endl '\n'



int main() { ___

    #ifdef BMO
        freopen("e.in", "r", stdin);
    #endif

    int n;

    while (cin>>n) {
        string text;
        cin>>text;
        for (int it = 0; it < n; ++it) {
            string pattern;
            cin>>pattern;
            for (int i = 0; i < pattern.size(); ++i) {
                if (pattern[i] == '*')
                    pattern[i]=' ';
            }
            stringstream ss(pattern);
            int ind = 0;
            int ok  = 1;
            string tmp;
            while (ss>>tmp) {
                int pos = text.find(tmp, ind);
                if (pos == string::npos ) {
                    ok = false;
                    break;
                }
                ind = (pos + tmp.size() +1);
            }
            if (ok)
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;
        }
    }
    return 0;
}



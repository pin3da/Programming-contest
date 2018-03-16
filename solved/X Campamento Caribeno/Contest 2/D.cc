#include<bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << (x) << endl;


int main() {
    long long a, b, c;
    while (cin >> a >> b >> c) {
        int g = __gcd(a, b);
        if (c % g) {
            cout << "Impossible" << endl;
        } else {
            long long x = 0;
            for (;;x++) {
                if ((c - a * x) % b) continue;
                long long y = (c - a * x) / b;
                if (a * x + b * y == c) {
                    break;
                }
            }
            cout << x << " " << (c - a * x) / b << endl;
        }

    }
    return 0;
}

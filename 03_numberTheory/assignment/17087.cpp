#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    if(b==0) {
        return a;
    }
    return gcd(b, a%b);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, s, a, d, tmp=0;
    cin >> n >> s;

    while(n--) {
        cin >> a;
        d = abs(s-a);
        if(tmp!=0) {
            tmp = gcd(max(tmp, d), min(tmp,d));
        }
        else {
            tmp = d;
        }
    }

    cout << tmp;

    return 0;
}
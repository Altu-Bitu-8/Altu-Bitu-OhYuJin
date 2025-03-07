#include <iostream>
#include <vector>
#include <cmath>

#define MAX 1000000

using namespace std;

void oddPrime(vector<bool>& v) { 
    // n 입력 받을 때마다 소수 판별 시 시간 초과
    int s=sqrt(MAX);

    for(int i=3; i<=s; i+=2) { // 홀수 숫자 소수 판별
        if(!v[i]) {
            continue; // 소수 아니면 탐색x
        }

        for(int j=i*i; j<=MAX; j+=i) {
            v[j]=false;
        }
    }
}

int goldbach(const int& n, const vector<bool>& v) {

    for(int i=3; i<=(n/2); i+=2) {
        if(v[i] && v[n-i]) {
            return i;
        }
    }
    return 1;

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,p=1;

    vector<bool> prime(MAX+1,true);

    oddPrime(prime);

    cin >> n;
    while (n!=0) {
        p = goldbach(n, prime);
        if (p==1) cout << "Goldbach's conjecture is wrong.\n";
        else cout << n << " = " << p << " + " << n-p << "\n"; 

        cin >> n;
    }
    return 0;
}
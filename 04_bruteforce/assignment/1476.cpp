#include <iostream>

using namespace std;

const int EARTH = 15;
const int SUN = 28;
const int MOON = 19;

int calYear(int e, int s, int m) {

    int k=1;

    if (e==EARTH) {
        e%=EARTH;
        // 아래 비교에서 나머지 계산 시 0으로 나오기 때문
    }

    if (m==MOON) {
        m%=MOON;
    }

    if (s==SUN) {
        s%=SUN;
    }

    while (true) {
        if((e==k%EARTH) && (s==k%SUN) && (m==k%MOON)) {
            return k;
        }
        k++;
    }
    return 0;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int E, S, M;
    cin >> E >> S >> M;

    cout << calYear(E, S, M);

    return 0;
}
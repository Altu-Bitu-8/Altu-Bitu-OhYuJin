#include <iostream>
#include <vector>

using namespace std;
const int DIVISOR = 10007;

void tilingTwoByN(vector<int>& t, int n) {
    for(int i=3; i<=n; i++) {
        t[i]=(t[i-1]+t[i-2])%DIVISOR;
        // int 범위 초과할 수 있으므로 미리 나누어주어야함
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // a_n = a_n-1 + a_n-2 (n>=3, a_1 = 1, a_2 = 2)
    // 맨 앞에 세워서 하나 추가한 경우 = 남은 길이 n-1 = a_n-1
    // 맨 앞에 눕혀서 두 개 추가한 경우 = 남은 길이 n-2 = a_n-2

    int n;
    cin >> n;
    vector<int> tiling(n+1,0);
    tiling[1] = 1; tiling[2] =2;

    tilingTwoByN(tiling, n);

    cout << tiling[n];

    return 0;
}
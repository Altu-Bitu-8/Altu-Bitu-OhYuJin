#include <iostream>

using namespace std;

typedef long long ll;
const int MAX = 60;

pair<int, int> getPair(ll m) {
    int x,y;
    
    // m이 제곱수인 경우
    for(ll i=1; i< MAX; i++) {
        if (m== ((ll)1<<i)) { // 1 << 32부터는 int 범위 초과하므로 ll 필요요
            return {i-1, i-1};
        }
    }

    // m이 제곱수 아닌 경우
    for(x=0; x < MAX; x++) {
        if(m & ((ll)1 << x)) { // m의 x번째 비트가 1이면
            m -= (ll)1 << x; // 해당 비트를 끔
            break; // x는 m의 가장 낮은 비트
        }
    }

    for(y=x+1; y < MAX; y++) {
        if(m & ((ll)1 << y)) { // m의 y번째 비트가 1이면
            break;
        }
    }
    return {x,y};

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    ll m;
    cin >> n;

    while (n--) {
        cin >> m;
        pair<int, int> ans = getPair(m);
        cout << ans.first<< " " << ans.second << "\n";
    }
    return 0;
}
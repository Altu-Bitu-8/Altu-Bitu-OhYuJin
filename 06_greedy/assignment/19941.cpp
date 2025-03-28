#include <iostream>
#include <vector>

using namespace std;

int canEatBurger(vector<char>& v, int k) {
    int size = v.size();
    int ans=0;

    for(int i=0; i<size; i++) {
        if(v[i]!='P') {
        // 사람 아니면 (햄버거, 또는 이미 매칭 후 빈자리) 다음으로
            continue;
        }

        for(int j=i-k; j<=i+k; j++) {
        // 가장 왼쪽 햄버거를 먹는 것이 최적
            if(0<=j && j<size && v[j]=='H') {
                ans++;
                v[i]=v[j]='0';
                break;
            }
        }
    }
    return ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;

    cin >> n >> k;
    vector<char> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    cout << canEatBurger(v, k);


    return 0;
}
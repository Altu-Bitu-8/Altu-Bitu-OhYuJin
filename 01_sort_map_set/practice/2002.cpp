#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// 추월한 차의 대수 구하는 함수
int overtake(int n, vector<int>& order_out) {
    int ans = 0;
    for (int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if (order_out[i] > order_out[j]) {
                ans++;
                break;
            }
        }
    }
    return ans;
}


int main()
{

    int n;
    cin >> n;
    
    string car;
    map<string, int> order_in;
    vector<int> order_out;
    
    for(int i=1; i<=n; i++) {
        cin >> car;
        order_in[car]=i;
    }
    
    for(int i=0; i<n; i++) {
        cin >> car;
        order_out.push_back(order_in[car]);
        //벡터 크기 미지정 시 push_back 사용
    }
    
    cout << overtake(n, order_out) << '\n';

    return 0;
}
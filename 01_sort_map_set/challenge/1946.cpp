#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ii;

int maxEmploy(vector<ii>& can) {
    // 첫번째 조건 순위 높은 기준(오름차순)으로 정렬
    sort(can.begin(), can.end());
        
    int cnt = 1; // 첫번째 사람은 무조건 선발
    int highest = can[0].second;
    for(int i=1; i<can.size(); i++) {
        if(can[i].second<highest) {
            highest = can[i].second;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<ii> candi(n, {0,0});

        for(int i=0; i<n; i++) {
            cin >> candi[i].first >> candi[i].second;
        }

        cout << maxEmploy(candi) << "\n";

    }

    return 0;
}
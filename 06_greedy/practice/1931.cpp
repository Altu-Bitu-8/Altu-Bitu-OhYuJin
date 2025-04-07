#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> time(n);
    for(int i=0; i<n; i++) {
    // 끝나는 시간 기준으로 문제 풀기 때문에 편의상 second, first로 받음
        cin >> time[i].second >> time[i].first;
    }

    sort(time.begin(), time.end());

    int finish = 0, cnt = 0;
    for(int i=0; i<n; i++) {
        // 회의 시작 시간이 이전 회의 종료보다 늦을 때
        if(time[i].second>=finish) {
            finish = time[i].first;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
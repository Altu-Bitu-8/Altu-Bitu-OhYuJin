#include <iostream>
#include <vector>

using namespace std;

int minHeight(const vector<int>& lamp, int n, int m) {
// 가로등 사이 거리의 절반, 첫 가로등과 0, 마지막 가로등과 n 중 최댓값이 최소 높이가 됨
    int ans = max(lamp[0], n-lamp[m-1]);
    // 첫 가로등과 시작점, 마지막 가로등과 끝점 사이의 거리 중 최대를 ans 초기값으로 설정
    for(int i=1; i<m-1; i++) {
        ans = max(ans, (lamp[i+1]-lamp[i]+1)/2);
        // 가로등 사이 거리의 절반(올림) 계산 후 최댓값으로 최대거리 업데이트
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    vector<int> lamp(m);

    for(int i=0; i<m; i++) {
        cin >> lamp[i];
    }

    cout << minHeight(lamp, n, m);

    return 0;
}
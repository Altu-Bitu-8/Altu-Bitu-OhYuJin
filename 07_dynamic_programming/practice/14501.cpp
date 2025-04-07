#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

void dpBottomUp(const vector<ii>& v, vector<int>& dp, int n) {
    for (int i=0; i<n; i++) {
        for(int j=i+v[i].first; j<=n; j++) {
            dp[j]=max(dp[j], dp[i]+v[i].second);
        }
    }
}

void dpTopDown(const vector<ii>& v, vector<int>& dp, int n) {
    for(int i=n-1; i>=0; i--) {
        if(i+v[i].first>n) { // 상담이 퇴사일 넘기면
            dp[i]=dp[i+1]; // 상담하지 않고 이전 값 유지
        }
        else { // 상담 하는 것과 하지 않는 것 중 큰 값 선택
            dp[i]= max(dp[i + 1], v[i].second + dp[i + v[i].first]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<ii> v(n);
    vector<int> dp(n+1, 0);
    // i일에 상담 1일짜리 상담 시 당일에 끝남, 수익은 i+1일에 반영
    // n일까지 완료 시 퇴사일인 n+1에 총 수익 저장됨
    // dp의 크기 n으로 유지 시 상담 끝나는 날에 수익 바로 저장해야함
    // i일에 끝나는 상담의 수익과 i일에 시작하는 상담 수입 겹치므로 갱신 제대로x 

    for(int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
        // int a,b; 선언 후 입력 받고 v.push_back(make_pair(a,b));도 가능
    }

    dpBottomUp(v, dp, n);
    cout << dp[n];

    // dpTopDown(dp, li, n);
    // cout << dp[0];

    return 0;
}
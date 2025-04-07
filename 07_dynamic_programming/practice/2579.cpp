#include <iostream>
#include <vector>

using namespace std;

int getMaxScore(int n, const vector<int>& score) {
    vector<int> dp(n+1,0);
    
    dp[1]=score[1];
    dp[2]=score[1]+score[2];

    for(int i=3; i<=n; i++) {
        // 하나 전인 경우 3칸 전의 최대 + 하나 전 계단 값
        dp[i]=max(dp[i-2], score[i-1]+dp[i-3]) + score[i];
    }

    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> score(n+1, 0);

    for(int i=1; i<=n; i++) {
        cin >> score[i];
    }

    cout << getMaxScore(n, score);

    return 0;
}
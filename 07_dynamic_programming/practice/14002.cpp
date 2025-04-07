#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> seq(n, 0);
    vector<int> dp(n,1);
    vector<int> arr;

    int len, max_len=1, max_idx=-1;

    for(int i=0; i<n; i++) {
        cin >> seq[i];
        len=1;
        for(int j=0; j<i; j++) {
            if(seq[i]>seq[j]) {
                len = max(dp[j]+1, len);
            }
        }
        dp[i] = len;

        if(max_len <= dp[i]) {
        // max_len을 1로 설정했기 때문에 길이 1인 경우 등호 없으면 반영 안됨
            max_len = dp[i];
            max_idx = i;
        }
    }

    int size=max_len;
    for(int i=max_idx; i>=0; i--) {
        if(dp[i]==max_len) {
            arr.push_back(seq[i]);
            max_len--;
        }
    }

    cout << size << "\n";
    for(int i=size-1; i>=0; i--) {
        cout << arr[i] << " ";
    }

    return 0;
}
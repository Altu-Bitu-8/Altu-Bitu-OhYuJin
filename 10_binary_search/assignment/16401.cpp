#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cntSnack(const vector<int>& len, int tmpLen) {
    // 길이가 tmpLen 일 때 과자 개수 세기
    int snack = 0;
    int size = len.size();
    for(int i=0; i<size; i++) {
        snack += len[i]/tmpLen;
    }
    return snack;
}

int maxLength(const vector<int>& len, int child) {
    int left=1;
    int right=len[len.size()-1];

    while(left<=right) {
        int mid = (left+right)/2;
        int cnt = cntSnack(len,mid);

        if(cnt>=child) { // 아이들 수보다 가능한 과자 수가 많으면
            left = mid+1; // 과자 하나 길이 늘림
        }
        else {
            right = mid-1;
        }
    }
    return right; // 마지막에 right left이므로 종료. right까지 가능
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m, n;
    cin >> m >> n;
    vector<int> length(n);
    for(int i=0; i<n; i++) {
        cin >> length[i];
    }
    sort(length.begin(), length.end());
    
    cout << maxLength(length, m);

    return 0;
}
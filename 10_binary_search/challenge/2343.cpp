#include <iostream>
#include <vector>

using namespace std;

int cntDisc(const vector<int>& lec, int length) {
    // 블루레이 하나의 길이가 length일 때 필요한 블루레이 개수 세기
    int disc = 0, tmp=0;
    int size = lec.size();
    for(int i=0; i<size; i++) {
        tmp+=lec[i];

        if(tmp==length) {
            disc++;
            tmp=0;
        }
        else if(tmp>length) {
            disc++;
            tmp=lec[i];
        }
    }

    if(tmp<length && tmp!=0) {
    // 마지막 강의 포함해도 tmp가 length보다 작으면 for문에서 디스크 개수 count 안됨
        disc++;
    }

    return disc;
}

int maxBluray(const vector<int>& lec, int m, int total, int max) {
    int left = max;
    int right = total; // 블루레이 하나의 길이 최대는 총 강의의 합

    while(left<=right) {
        int mid = (left+right)/2;
        int cnt = cntDisc(lec, mid);

        if(cnt<=m) { // 더 적은 블루레이 필요, 길이 줄여야함
            right = mid -1;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, total=0, max_len=0;
    cin >> n >> m;
    vector<int> lecture(n);
    for(int i=0; i<n; i++) {
        cin >> lecture[i];
        total +=lecture[i];
        max_len=max(max_len,lecture[i]);
    }

    cout << maxBluray(lecture, m, total, max_len);

    return 0;
}
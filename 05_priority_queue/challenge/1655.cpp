#include <iostream>
#include <queue>

using namespace std;

void findMedian(int n) {
    int x;
    priority_queue<int> max; //작은 값들 저장, top이 중앙값
    priority_queue<int, vector<int>, greater<int>> min; // 중앙값보다 큰 값들 저장

    for(int i=1; i<=n; i++){
        cin >> x;
        if(i%2==1) { // 홀수 번째이면 max에
            max.push(x);
        }
        else { // 짝수 번째이면 min에
            min.push(x);
        }

        if(i!=1) {
            int max_t = max.top();
            int min_t = min.top();

            if(max_t > min_t) {
                max.pop();
                max.push(min_t);
                min.pop();
                min.push(max_t);
            }
        }
        cout << max.top() << "\n";
    }
}

void answerVersion(int n) {
// 새로운 숫자가 입력되면, 우선 현재 '가운데'를 기준으로 상위 숫자인지, 하위 숫자인지 구분하여 힙에 삽입
// 상위 숫자와 하위 숫자의 크기는 같거나, 하위 숫자가 1개 더 많아야 함.
    
    int x;
    priority_queue<int> upper; //작은 값들 저장, top이 중앙값
    priority_queue<int, vector<int>, greater<int>> lower; // 중앙값보다 큰 값들 저장

    while (n--) {
        cin >> x;

        // 상위 숫자 중 최솟값보다 더 큰 값이 들어온 경우
        if (!upper.empty() && x > upper.top()) {
            upper.push(x);  // 상위 숫자에 추가
        } else {
            lower.push(x);  // 하위 숫자에 추가
        }

        // 하위 숫자와 상위 숫자는 개수가 같거나, 하위 숫자가 1크도록 유지되어야 함.
        if (lower.size() < upper.size()) {  // 상위 숫자가 더 많다면 하위 숫자로 옮기기
            lower.push(upper.top());
            upper.pop();
        } else if (lower.size() > upper.size() + 1) {  // 하위 숫자가 상위 숫지 +1 보다 더 많은 경우
            upper.push(lower.top());
            lower.pop();
        }

        cout << lower.top() << '\n';
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    findMedian(n);

    return 0;
}
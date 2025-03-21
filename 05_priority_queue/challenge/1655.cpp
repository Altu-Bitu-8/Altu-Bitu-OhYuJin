#include <iostream>
#include <queue>

using namespace std;

void findMedian(int n) {
    int x;
    priority_queue<int> max; //작은 값들 저장, top이 중앙값
    priority_queue<int, vector<int>, greater<int>> min;
    // 중앙값보다 큰 값들 저장

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

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    findMedian(n);


    return 0;
}
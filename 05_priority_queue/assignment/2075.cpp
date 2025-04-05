#include <iostream>
#include <queue>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    // min heap

    for(int i=0; i<n*n; i++) {
        cin >> x;
        pq.push(x);
        if(pq.size()>n) {
            pq.pop(); // n*n개 모두 저장시 메모리 초과
        }
    }

    // 최소힙 사용하여 n개만 저장하고 나면, top이 n번째로 큰 수
    cout << pq.top();

    return 0;
}
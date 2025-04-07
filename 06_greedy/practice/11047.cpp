#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int stackVersion(int n, int k) {
    int a, ans=0;
    stack<int> value;

    while(n--) {
        cin >> a;
        value.push(a);
    }

    while(k!=0 && !value.empty()) {

        int top = value.top();

        if(top>k) {
            value.pop();
        }
        else if(top==k) {
            ans++;
            k=0;
        }
        else { // top < k
            ans += k/top;
            k %= top;
            value.pop();
        }
    }

    return ans;
}

int vectorVersion(int n, int k) { // 라이브코딩 방식
    int ans=0;
    vector<int> A(n, 0);
	
	// 동전 가치 입력
	for(int i = 0; i < n; i++) {
		cin >> A[i];
	}
	
	while (n--) { // 큰 가치부터 검사하기 (동전 개수의 '최솟값'을 구해야하므로)
	    ans += k / A[n];
	    k %= A[n];
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    cout << stackVersion(n,k);

    return 0;
}
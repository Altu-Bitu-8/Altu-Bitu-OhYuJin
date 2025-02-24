#include <iostream>
#include <stack>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int i = a.size()-1, j = b.size()-1;

    stack<int> ans;
    int sum, carry=0;

    while(i>=0 || j >=0 || carry) {
    // 마지막 최고자리 합에서 carry 존재 할 수도 있고 아닐 수도 있기 때문
        sum = carry;
        if (i>=0) sum+= a[i] - '0'; // char을 숫자로 변환
        if (j>=0) sum+= b[j] - '0';
        carry = sum/10;
        ans.push(sum%10);
        i--; j--;
    }

    while(!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

bool isTreeSuc(int sum, int odd) {
    if(sum%3) {
    // 한 번에 3씩 자라므로 모든 나무 높이 합이 3의 배수여야 함
        return false;
    }

    if(odd>sum/3) {
    // sum/3 : 물 주는 횟수
    // 최소 홀수 나무 개수만큼은 1씩 자라는 물뿌리개 필요
        return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, sum=0, odd=0;
    cin >> n;
    
    while(n--) {
        int h;
        cin >> h;
        sum +=h;
        
        if(h%2) {
            odd++;
        }
    }

    // 삼항연산자 'condition ? A : B' 형태
    isTreeSuc(sum, odd) ? cout << "YES" : cout << "NO";

    return 0;
}
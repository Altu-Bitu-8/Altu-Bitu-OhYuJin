// bruteforce 방식은 시간초과

#include <iostream>
#include <vector>

using namespace std;

int minVelocityBruteforce(const vector<int>& v, int max) {
    // bruteforce 방식은 시간초과

    // 처음 시도할 속도가 최댓값보다 크면서 첫 행성의 배수이도록
    int a = max/v[0];
    if(max%v[0]!=0) {
        a++;
    }

    // long long으로 해야함
    long long ans = (long long)v[0]*a;
    
    long long tmp = ans;
    int size =v.size();
    for(int i=1; i<size; i++) {
        if(tmp%v[i]==0) {
        // 배수이면 다음 행성으로 넘어감
            continue;
        }
    
        if (tmp<v[i]) {
        // 속도가 필요 속도보다 작으면 첫 행성만큼 더함 (첫 행성 배수여야하므로)
            ans+=v[0];
            i=0;
            tmp = ans;
            continue;
        } // 배수가 아니지만 속도가 충분히 크면 배수가 되도록 맞춤
        tmp -= (tmp%v[i]);
    }
        // break 없이 for문 종료 시 모두 성공하였으므로 break;

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    int max=0;
    for(int i=0; i<n; i++) {
    // 행성별 필요 속도 입력 받고 최댓값 찾기
        cin >> v[i];
        if(max<v[i]) {
            max = v[i];
        }
    }

    cout << minVelocityBruteforce(v, max);

    return 0;
}
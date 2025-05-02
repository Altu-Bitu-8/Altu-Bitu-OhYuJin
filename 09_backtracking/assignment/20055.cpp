#include <iostream>
#include <deque>

using namespace std;

void moveBelt(int n, deque<int>& seq, deque<bool>& use) {
    // 벨트 회전
    seq.push_front(seq.back());
    seq.pop_back();

    use.push_front(use.back());
    use.pop_back();
    use[n-1]=false;

    // 로봇 이동
    for(int i=n-2; i>=0; i--) {
    // 앞 로봇부터 이동시키면 중복 발생
        if(!use[i]) { // 현재 위치 사용 중 아니면 넘어감
            continue;
        }
        if(use[i+1] || seq[i+1]<=0) {
        // 현재 위치 사용 중이지만 다음으로 가는 것이 불가하면 넘어감
            continue;
        }
        use[i]=false;
        use[i+1]=true;
        seq[i+1]--;
    }
    use[n-1]=false;

    // 로봇 올리기
    if(!use.front() && seq.front()>0) {
        use.front()=true;
        seq.front()--;
    }
}

bool zeroUnderK(int n, int k,const deque<int>& seq) {
    // 내구도 0인 위치가 k개 미만인지 확인
    int tmp=0;
    for(int i=0; i<2*n; i++) {
        if(seq[i]==0) {
            tmp++;
        }
        if(tmp>=k) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    deque<int> seq(2*n);
    deque<bool> use(2*n, false);

    for(int i=0; i<2*n; i++) {
        cin >> seq[i];
    }

    int ans=0;
    do {
        moveBelt(n, seq, use);
        ans++;
    } while(zeroUnderK(n, k, seq));

    cout << ans;

    return 0;
}
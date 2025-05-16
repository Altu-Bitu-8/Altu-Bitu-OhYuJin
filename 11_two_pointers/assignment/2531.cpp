#include <iostream>
#include <vector>
#include <map>

using namespace std;

int maxSushi(const vector<int>& sushi, int n, int k, int c) {
    int ans=0, coup=1;
    map<int, int> m;

    for(int i=0; i<k; i++) { // 처음 k개 map에 넣음
        if(sushi[i]==c) {
        // 쿠폰과 같으면 쿠폰 못 쓰는 것으로 0 설정
            coup = 0;
        }
        m[sushi[i]]++;
    }

    ans = m.size()+coup; // map에 있는 종류 + 쿠폰 수

    for(int i=0; i<n; i++) {
        m[sushi[i]]--;
        if(m[sushi[i]]==0) {
            m.erase(sushi[i]);
        }

        m[sushi[(i+k)%n]]++; // 사이즈 k의 슬라이딩 윈도우

        coup = m.count(c) ? 0 : 1; // map에 c 존재하지 않으면 쿠폰 수 1
        ans = max(ans, (int)m.size()+coup);
        // map.size()는 size_t형이므로 변환
    }
    
    return ans;

}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,d,k,c;
    cin >> n >> d >> k >> c;
    vector<int> sushi(n+k-1);
    for(int i=0; i<n; i++) {
        cin >> sushi[i];
    }

    cout << maxSushi(sushi, n, k, c);

    return 0;
}
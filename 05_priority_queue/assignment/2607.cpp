#include <iostream>
#include <vector>

using namespace std;
const int ALPHABET=26;

void countFreq(string word, vector<int>& v) {
    for(char ch : word) {
        v[ch - 'A']++;
    }
}

int findSimiliar(const vector<int>& first, const vector<int>& input) {
    int diff=0;
    for(int i=0; i<ALPHABET; i++) {
        diff += abs(first[i]-input[i]);

    /*어차피 diff>2에서 걸러지므로 아래 코드 대신 한 줄로 줄일 수 있음
        if(first[i]!=input[i]) {
            if(abs(first[i]-input[i])>1) {
            // 특정 알파벳 개수 차이 2이상인 경우 불가
                return 0;
            }
            diff++;
        } */

        if(diff>2) {
        // diff가 3이상이면 서로 한 알파벳 이상이 다른 것
            return 0;
        }
    }
    /* for문 종료 시 구성, 개수 같은 경우(diff=0), 구성 같지만 알파벳 하나의 개수 차이가 1인 경우(diff=1)
        총 알파벳 개수 같지만 구성이 1개 달라 변경이 가능한 경우(diff2)만 남음*/
    return 1;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    string in;
    vector<int> first(ALPHABET,0);

    cin >> n >> in;
    int size = in.length();

    countFreq(in, first);

    int ans=0;

    for(int i=0; i<n-1; i++){
        cin >> in;
        if(abs(size-(int)in.length())>1) {
        // 두 단어의 길이 차 2이상이면 검사x
            continue;
        }
        vector<int> input(ALPHABET,0);
        countFreq(in, input);
        ans +=findSimiliar(first, input);
    }

    cout << ans;

    return 0;
}
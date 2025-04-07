#include <iostream>

using namespace std;
string solution(string number, int k) {

    string answer = "";
    int max = 0;
    int max_idx = 0;
    int idx = 0;

    while(idx < number.length()) {
        if(max<number[idx]) {
            max = number[idx];
            max_idx = idx;
        }

        if(idx==k) {
        // k: 한 번 탐색하는 인덱스의 최댓값
        // (0~k까지 k+1개 중 최소한 최댓값 1개는 선택하므로 나머지 최대 k개까지 버림 가능)
        // k까지 다 탐색하면, 앞서 탐색한 숫자들 중 최댓값부터 다시 탐색 시작
        // 앞부분을 추가하지 않기 위함
            idx = max_idx;
            k++; //다음 탐색 범위 확대(k, k+1, ..., number.length() )
            answer.push_back(max);
            max=0;
        }
        idx++;
    }

    return answer;
}
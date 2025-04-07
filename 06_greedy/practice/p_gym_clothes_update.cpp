#include <string>
#include <vector>

using namespace std;
const int MAX =2;

// 라이브코딩 버전
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n+1,1); // 체육복 수 저장
    for(int i=0; i<lost.size(); i++) {
        student[lost[i]]--;
    }
    for(int i=0; i<reserve.size(); i++) {
        student[reserve[i]]++;
    }
    
    for(int i=1; i<=n; i++) {
        if(student[i]>=1) { // 체육복 개수 1개 이상이면 스킵
            continue;
        }
        // 체육복 개수 0인 사람만 남음
        if(student[i-1]==MAX) { // 앞사람 확인
            student[i]++;
            student[i-1]--;
        }
        else if(student[i+1]==MAX) { // 뒷사람 확인
            student[i]++;
            student[i+1]--;
        }
    }

    for(int i=1; i<=n; i++) {
        if(student[i]>=1) { //체육복 개수 1이상이면 정답++
            answer++;
        }
    }
    
    return answer;
}
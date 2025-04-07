#include <string>
#include <vector>

using namespace std;

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
        if(student[i]>1 && student[i+1]==0 && i<n) {
            student[i]--;
            student[i+1]++;
            answer+=2;
            i++;
        }
        else if(student[i]==0 && student[i+1]>1 && i<n) {
            student[i]++;
            student[i+1]--;
            answer+=2;
            i++;
        }
        else if(student[i]>=1) {
            answer++;
        }
    }
    
    return answer;
}
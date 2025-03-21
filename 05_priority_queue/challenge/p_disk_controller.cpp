#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp{
    bool operator() (const vector<int>& p, const vector<int>& c) {
        return p[1] > c[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int size = jobs.size();
    int cnt=1; // 큐에 작업 다 넣었는지 확인
    
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    
    sort(jobs.begin(), jobs.end());
    // 요청 시점 기준 오름차순 정렬
    
    // 가장 맨 처음은 큐에 넣지 않고 바로 실행
    int time = jobs[0][0] + jobs[0][1];
    int turntime = jobs[0][1];
    
    while(cnt < size || !pq.empty()) {
        if(cnt < size && jobs[cnt][0]<=time) {
        // 아직 큐에 넣을 작업 남아있고, 현재 시간이 요청 시간보다 작거나 같아야 큐에 넣을 수 있음
            pq.push(jobs[cnt]);
            cnt++;
            continue;
        }
        if (!pq.empty()) {
            vector<int> tmp = pq.top();
            time += tmp[1];
            turntime += time-tmp[0];
            pq.pop();
        }
        else { // 큐 비어있지만 아직 모든 작업 실행하지 않았다면
            time = jobs[cnt][0]; // 다음 작업 요청 시간으로 time 변경
        }
    }
    
    answer = turntime/size;
    
    return answer;
}

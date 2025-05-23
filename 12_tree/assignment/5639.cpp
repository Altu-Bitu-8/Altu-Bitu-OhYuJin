#include <iostream>
#include <vector>

using namespace std;

void preToPost(const vector<int>& input, int start, int end) {
    if(start >= end) { 
        return;
    }
    
    int rc=end;
    // 오른쪽 서브트리 시작점. 없을 경우 대비하여 기본값 end
    for(rc=start+1; rc<end; rc++) {
        if(input[start]<input[rc]) {
        // 기준보다 처음으로 커지는 순간부터 오른쪽 서브트리
            break;
        }
    }

    preToPost(input, start+1, rc); //왼쪽 서브트리 [start+1, rc)
    preToPost(input, rc, end); // 오른쪽 서브트리 [rc, end)
    cout << input[start] << "\n";

    return;    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int x;
    vector<int> input;
    while(cin >> x) {
        input.push_back(x);
    }

    preToPost(input, 0, input.size());

    return 0;
}

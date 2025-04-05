#include <iostream>
#include <vector>

using namespace std;

vector<int> merged; // 다시 merge 할 때 채워지는 배열

// 머지 소트 : O(nlogn)
void merge(vector<int>& arr, int left, int mid, int right) {
    int pl= left, pr = mid+1, idx = left;
    
    while(pl <= mid && pr <= right) {
    // 둘 중 한 쪽이 모두 나열되면 종료
        if (arr[pl] < arr[pr]) {
            merged[idx++] = arr[pl++];
            // merged의 idx번째에 arr의 pl번째 값 넣은 후 각각 +1
        } else {
             merged[idx++] = arr[pr++];
        }
    }
    
    while(pl <= mid) {
    // 만약 위에서 pr이 끝나 종료되었다면 p1은 남았으므로
        merged[idx++] = arr[pl++];
    }
    
    while(pr <= right) {
    // 만약 위에서 pl이이 끝나 종료되었다면 pr은 남았으므로
        merged[idx++] = arr[pr++];
    }
    
    for (int i = left; i<=right; i++) {
        arr[i] = merged[i];
    }
    
    
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left<right) {
        int mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> arr(n);
    merged.assign(n,0); // 전역 변수 크기 n 할당, 0으로 값 초기화
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        
    }
    mergeSort(arr, 0, n-1);
    
    for (int i=0; i<n; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}
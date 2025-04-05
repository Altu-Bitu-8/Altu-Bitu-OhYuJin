#include <iostream>
#include <vector>

using namespace std; // 쓰면 std::cin 안해도 됨

// 버블 정렬 : O(n^2)
void bubbleSort(vector<int>& arr) {
    for(int i=0; i<arr.size()-1; i++) {
    // 하나씩 정렬 하다가 마지막 1개 남았을 때는 정렬 필요 없으므로 -1
        bool is_swap = false; //swap 여부 표시
        
        for(int j=0; j<arr.size()-i-1;j++) {
        // 0~n-1까지 정렬 -> 0~n-2까지 정렬 -> ... -> 0~1까지 정렬
            if (arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]); // c++ 기본 내재 함수
                is_swap = true;
            }
        } if (!is_swap) // swap이 한 번도 일어나지 않는다면
              return; // 이미 모든 원소가 정렬되어 있으므로 return 
    }
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        
    }
    bubbleSort(arr);
    
    for (int i=0; i<n; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}
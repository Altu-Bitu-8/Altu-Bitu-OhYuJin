#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student {
    string name;
    int kor, eng, math;
};

bool comp(const student& s1, const student& s2) {
    if (s1.kor != s2.kor) {
        return s1.kor > s2.kor;
    }
    if (s1.eng != s2.eng) {
        return s1.eng < s2.eng;
    }
    if (s1.math != s2.math) {
        return s1.math > s2.math;
    }
    return s1.name < s2.name; // 이름 사전식 배열
}

int main()
{
    int n;
    cin >> n;
    
    vector<student> my_class(n);
   
    for(int i=0; i<n; i++) {
        cin >> my_class[i].name >> my_class[i].kor >> my_class[i].eng >> my_class[i].math;
    }
    
    sort(my_class.begin(), my_class.end(), comp);
    
    for (int i=0; i<n; i++) {
        cout << my_class[i].name << '\n';
    }

    return 0;
}
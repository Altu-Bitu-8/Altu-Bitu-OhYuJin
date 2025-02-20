#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// 자리수 합 계산 함수
int sumDigits(const string& s) {
	int sum = 0;
	for (int i = 0; i < s.size(); i++) { // for (char c : s)도 가능
		if (isdigit(s[i])) {
			sum += s[i]-'0';
			// int로 형변환 위해. stoi()는 char가 아닌 string 변환이기 때문에 불가
		}
	} return sum;
}


// 정렬 조건 함수
bool comp(const string& s1, const string& s2) {
// comp()에서는 실제 정렬이 이루어지는 것이 아니기 때문에 const 가능
	if (s1.size() != s2.size()) {
		return s1.size() < s2.size();
	}

	int sum1 = sumDigits(s1);
	int sum2 = sumDigits(s2);

	if (sum1 != sum2) {
		return sum1 < sum2;
	}

	return s1 < s2;
}

int main() {

	int n;
	cin >> n;
	vector<string> serial(n);

	for (int i = 0; i < n; i++) {
		cin >> serial[i];
	}

	sort(serial.begin(), serial.end(), comp);
	
	for (int i = 0; i < n; i++) {
		cout << serial[i] << '\n';
	}

	return 0;
}
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

void withoutChange(map<string, int>& m) {
	m["W_without"] += (m["I"] - (m["I0"] + m["A"])) * m["D"];
}

void withChange(map<string, int>& m) {
	for (int i = 0; i < m["D"]; i++) {
		m["delta"] = m["I"] - (m["I_with"] + m["A"]);
		m["W_with"] += m["delta"];

		if (abs(m["delta"]) > m["T"]) {
			m["I_with"] += floor(m["delta"] / 2.0);
		}
	}
}

int main() {
	map<string, int> m;
	m["A0"] = 0; 
	cin >> m["W0"] >> m["I0"] >> m["T"];
	cin >> m["D"] >> m["I"] >> m["A"];
	//초기값 설정하여 코드 오류로 계산이 안되어 0 나오는 경우 없도록
	m["W_without"] = m["W0"];
	m["W_with"] = m["W0"];
	m["I_with"] = m["I0"];


	withoutChange(m);
	if (m["W_without"] <= 0) {
		cout << "Danger Diet" << '\n';
	}
	else {
		cout << m["W_without"] << " " << m["I0"] << '\n';
	}
	
	withChange(m);
	if (m["W_with"] <= 0 || m["I_with"]<=0) {
		cout << "Danger Diet" << '\n';
		return 0;
	}
	
	cout << m["W_with"] << " " << m["I_with"] << " ";
	
	if (m["I0"] - m["I_with"] > 0) cout << "YOYO";
	else cout << "NO";

	return 0;
}